#!/usr/bin/env python3
"""
ukf.py: 
    Class for GPS + IMU Fusion.     

Author: Hyo-Eun Kang 
Data  : 2024.12.
"""
import rclpy
from rclpy.node import Node
import numpy as np
import utm
import scipy
from scipy.spatial.transform import Rotation as R

from geometry_msgs.msg import PoseStamped
from wamv_msgs.msg import NavigationType
from std_msgs.msg import Float64, Header
from sensor_msgs.msg import NavSatFix, Imu

class UKF(Node):
    def __init__(self):
        super().__init__('ukf_node')

        self.prev_time = None
        self.prev_position = None
        self.psi = 0.0  # 초기 헤딩
        self.dt = 1/20

        # 초기 목표 위치 설정
        self.goal_x = 0.0
        self.goal_y = 0.0

        self.u = 0.0
        self.v = 0.0
        self.r = 0.0  # 초기 yaw rate
        self.w = 0.0  # 초기 쿼터니언의 w 값

        self.imu_data = np.zeros(3) # [a_x, a_y, omega_z]

        self.origin_e = 284480.02
        self.origin_n = 6266152.97
        self.dim_x = 6  # 상태 벡터 크기: [x, y, psi, u, v, r]
        self.dim_z = 2  # 측정 벡터 크기: [x, y] (GPS)
        self.x = np.zeros(self.dim_x)  # 초기 상태
        max_variance = 1e4
        self.P = np.eye(self.dim_x) * 1.0  # 초기 공분산
        self.P = np.clip(self.P, -max_variance, max_variance)
        self.Q = np.eye(self.dim_x) * 0.05  # 약간 증가
        self.R = np.diag([1.0, 1.0])  # GPS 노이즈를 약간 증가
        self.Wm, self.Wc = self._calculate_weights()

        # subscription
        self.gps_fix_subscriber   = self.create_subscription(NavSatFix, '/wamv/sensors/gps/gps/fix',  self.gps_fix_callback,   20)
        self.imu_data_subscriber  = self.create_subscription(Imu,       '/wamv/sensors/imu/imu/data', self.imu_data_callback,  20)

        # Publish
        self.fusion_nav_publisher = self.create_publisher(NavigationType, '/ukf_navigation', 20)
        self.fusion_cov_publisher = self.create_publisher(Float64, '/ukf_covariance', 20)

        # Set timer
        self.timer = self.create_timer(self.dt, self.run_ukf)

    def get_yaw_from_quaternion(self, quat):
        r = R.from_quat([quat.x, quat.y, quat.z, quat.w])
        _, _, yaw = r.as_euler('xyz', degrees=False)
        return yaw

    def transform_to_body_frame(self, vx, vy, yaw):
        u = vx * np.cos(yaw) + vy * np.sin(yaw)
        v = -vx * np.sin(yaw) + vy * np.cos(yaw)
        return u, v

    def imu_data_callback(self, msg):
        # IMU 데이터를 UKF 예측에 사용
        a_x = msg.linear_acceleration.x
        a_y = msg.linear_acceleration.y
        omega_z = msg.angular_velocity.z
        self.imu_data = np.array([a_x, a_y, omega_z])

    def gps_fix_callback(self, msg):
        # GPS 좌표를 UTM 좌표로 변환
        e, n, _, _ = utm.from_latlon(msg.latitude, msg.longitude)
        current_position = np.array([e - self.origin_e, n - self.origin_n])

        # 현재 위치와 시간 저장
        self.prev_position = current_position
        self.prev_time = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9

        if self.prev_position is None:
            self.prev_position = current_position
            self.x[0:2] = current_position
            self.P = np.eye(self.dim_x) * 1.0  # 초기 공분산
            self.get_logger().info("GPS initialized.")
            return


        self.update(current_position)

    def run_ukf(self):
        # UKF 예측 단계
        self.predict(self.imu_data)

        # 퍼블리시 UKF 결과
        self.publish_fusion_nav_msg()

    def publish_fusion_nav_msg(self):
        # 추정된 상태를 NavigationType 메시지로 변환하여 퍼블리시
        nav_msg = NavigationType()
        nav_msg.header = Header()
        nav_msg.header.stamp = self.get_clock().now().to_msg()
        nav_msg.header.frame_id = 'WAM-V'
        nav_msg.x = self.x[0]
        nav_msg.y = self.x[1]
        nav_msg.psi = self.x[2]
        nav_msg.u = self.x[3]
        nav_msg.v = self.x[4]
        nav_msg.r = self.x[5]
        self.fusion_nav_publisher.publish(nav_msg)

        # 디버깅 출력
        self.get_logger().info(f"State: {self.x}")
        self.get_logger().info(f"Covariance Trace: {np.trace(self.P)}")
        self.get_logger().info(f"Process Noise Q:\n{self.Q}")
        self.get_logger().info(f"Measurement Noise R:\n{self.R}")

        # 공분산의 추정 정확도 퍼블리시
        covariance_msg = Float64()
        covariance_msg.data = np.trace(self.P)
        self.fusion_cov_publisher.publish(covariance_msg)

    def _calculate_weights(self):
        alpha = 0.001
        beta = 2
        kappa = 3 - self.dim_x
        lambda_ = alpha**2 * (self.dim_x + kappa) - self.dim_x
        Wm = np.full(2 * self.dim_x + 1, 0.5 / (self.dim_x + lambda_))
        Wm[0] = lambda_ / (self.dim_x + lambda_)
        Wc = Wm.copy()
        Wc[0] += 1 - alpha**2 + beta
        return Wm, Wc

    def predict(self, imu_data):
        # 시그마 포인트 생성
        sigma_points = self._generate_sigma_points()
        # 상태 전이 모델을 적용해 예측
        sigma_points_pred = np.array([self._f(pt, imu_data) for pt in sigma_points])
        # 예측 상태와 공분산 계산
        self.x = np.dot(self.Wm, sigma_points_pred)
        self.P = self.Q + sum(
            self.Wc[i] * np.outer(sigma_points_pred[i] - self.x, sigma_points_pred[i] - self.x)
            for i in range(2 * self.dim_x + 1)
        )

    def update(self, gps_data):
        # 시그마 포인트 생성
        sigma_points = self._generate_sigma_points()
        # 측정 모델 적용
        sigma_points_meas = np.array([self._h(pt) for pt in sigma_points])
        z_pred = np.dot(self.Wm, sigma_points_meas)
        Pz = self.R + sum(
            self.Wc[i] * np.outer(sigma_points_meas[i] - z_pred, sigma_points_meas[i] - z_pred)
            for i in range(2 * self.dim_x + 1)
        )
        Pxz = sum(
            self.Wc[i] * np.outer(sigma_points[i] - self.x, sigma_points_meas[i] - z_pred)
            for i in range(2 * self.dim_x + 1)
        )
        
        # 수치 안정성을 위해 Pz에 작은 값 추가
        Pz += np.eye(Pz.shape[0]) * 1e-6
        self.get_logger().info(f"Pz matrix:\n{Pz}")

        try:
            # 칼만 이득 계산
            K = Pxz @ np.linalg.inv(Pz)
        except np.linalg.LinAlgError:
            self.get_logger().error("Singular matrix detected in Pz. Using pseudo-inverse.")
            K = Pxz @ np.linalg.pinv(Pz)  # 특이 행렬에 대해 유사 역행렬 사용

        # 상태 업데이트
        self.x += K @ (gps_data - z_pred)
        self.P -= K @ Pz @ K.T


    def _generate_sigma_points(self):
        n = self.dim_x
        try:
            # P 안정화를 위해 작은 값 추가
            self.P += np.eye(n) * 1e-6
            sqrt_P = np.linalg.cholesky((n + 0.001) * self.P)
        except np.linalg.LinAlgError:
            self.get_logger().error("Matrix P is not positive definite. Attempting to fix...")
            # 비양의 정부호 행렬 복구
            min_eigenvalue = np.min(np.linalg.eigvals(self.P))
            if min_eigenvalue < 0:
                self.P += np.eye(n) * (-min_eigenvalue + 1e-6)
            sqrt_P = np.linalg.cholesky((n + 0.001) * self.P)
        sigma_points = np.zeros((2 * n + 1, n))
        sigma_points[0] = self.x
        for i in range(n):
            sigma_points[i + 1] = self.x + sqrt_P[i]
            sigma_points[n + i + 1] = self.x - sqrt_P[i]
        return sigma_points

    def _f(self, x, imu_data):
        x_new = x.copy()
        u, v, r = x[3:6]
        a_x, a_y, omega_z = imu_data
        psi = x[2]

        # 위치 변화
        x_new[0] += (u * np.cos(psi) - v * np.sin(psi)) * self.dt
        x_new[1] += (u * np.sin(psi) + v * np.cos(psi)) * self.dt
        # 속도 변화
        x_new[3] += a_x * self.dt
        x_new[4] += a_y * self.dt
        # yaw 변화
        x_new[2] += r * self.dt
        x_new[5] = omega_z
        return x_new

    def _h(self, x):
        # GPS 측정 모델
        return x[0:2]  # [x, y]


def main(args=None):
    rclpy.init(args=args)
    try:
        ukf_node = UKF()
        ukf_node.get_logger().info('UKF NODE')        
        try:
            rclpy.spin(ukf_node)
        except KeyboardInterrupt:
            ukf_node.get_logger().info('Keyboard Interrupt (SIGINT)')
        finally:
            ukf_node.destroy_node()
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()