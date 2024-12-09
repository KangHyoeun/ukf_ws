#!/usr/bin/env python3
"""
kmj_control.py:
    논문 "쌍동형 무인선의 동적 위치 제어에 관한 연구" 구현한 코드
"""

import rclpy
from rclpy.node import Node
import numpy as np
import time
from wamv_msgs.msg import NavigationType, ControlType, GuidanceType
from std_msgs.msg import Float64

from .lib.control_tool import NonlinearPDControl
from .lib.gnc_tool import saturation, ssa

class Control(Node):
    def __init__(self):
        super().__init__('dp_control_node')
        
        # 경유점 리스트 초기화
        self.waypoints = [(10.0, 10.0), (30.0, 30.0), (1.0, 1.0)]  # 삼각형 경로
        self.current_waypoint_index = 0  # 현재 경유점 인덱스
        self.waypoint_tolerance = 2.0  # 경유점 도달 거리 임계값
        self.x_waypoint, self.y_waypoint = self.waypoints[self.current_waypoint_index]

        # Initial subscriber data
        self.navigation_data    = None
        self.desired_psi        = None
        self.error_psi          = None

        # ROS2 publishers and subscribers for thruster commands
        self.create_subscribers_and_publishers()

        # 주기적인 제어 메시지를 보내기 위한 타이머
        self.dt    = 0.1
        self.timer = self.create_timer(self.dt, self.control_loop)

        # Get Parameter
        self.kp_x = 10.0
        self.kd_x = 0.0
        self.kp_y = 10.0
        self.kd_y = 0.0
        self.kp_psi = 6.0
        self.kd_psi = 0.1

        # 임시 목표 위치 설정을 위한 파라미터
        self.max_search_radius = 10.0  # 탐색 반경 (미터 단위)
        self.search_step = 0.1  # 탐색 간격 (미터 단위)        

        # azimuth 각도 변화율 제한 설정
        self.max_azimuth_change_rate = np.deg2rad(5.0)  # 10도/초로 제한

        # 이전 azimuth 각도 값 초기화
        self.prev_theta1 = 0.0
        self.prev_theta2 = 0.0

        # PWM 변화율 제한 코드 추가
        self.prev_pwm1, self.prev_pwm2 = 0.0, 0.0
        self.max_pwm_change_rate = 10.0  # 원하는 PWM 변화율 제한 값

        # Set class
        self.Control     = NonlinearPDControl()

    def create_subscribers_and_publishers(self):
        self.navigation_subscriber = self.create_subscription(NavigationType, '/navigation', self.navigation_callback, 20)

        # ROS2 publishers for thruster commands
        self.guidance_publisher     = self.create_publisher(GuidanceType, '/guidance', 20)
        self.control_publisher      = self.create_publisher(ControlType, '/control', 20)
        self.left_pos_publisher     = self.create_publisher(Float64, '/wamv/thrusters/left/pos', 20)
        self.left_thrust_publisher  = self.create_publisher(Float64, '/wamv/thrusters/left/thrust', 20)
        self.right_pos_publisher    = self.create_publisher(Float64, '/wamv/thrusters/right/pos', 20)
        self.right_thrust_publisher = self.create_publisher(Float64, '/wamv/thrusters/right/thrust', 20)

    def navigation_callback(self, msg):
        self.navigation_data = msg
        self.x   = self.navigation_data.x
        self.y   = self.navigation_data.y
        # self.psi = self.navigation_data.psi
        self.psi = np.deg2rad(self.navigation_data.psi) # rad
        self.u   = self.navigation_data.u
        self.r   = self.navigation_data.r

        self.position = np.array([self.x, self.y]) 

    def control_loop(self):

        if self.navigation_data is None:
            self.get_logger().info(f'check the goal and navigation data!', once = True)
            return
        
        # 목표 위치와의 거리 및 방위각 오차 계산
        self.target_position = np.array([self.x_waypoint, self.y_waypoint])
        distance             = np.linalg.norm(self.target_position - self.position)

        # 경유점 도달 여부 확인
        if distance < self.waypoint_tolerance:
            self.get_logger().info(f"Waypoint {self.current_waypoint_index} reached!")
            self.current_waypoint_index = (self.current_waypoint_index + 1) % len(self.waypoints)
            self.target_position = np.array(self.waypoints[self.current_waypoint_index])
            self.get_logger().info(f"Moving to waypoint {self.current_waypoint_index}: {self.target_position}")

        # 추력 할당 가능 여부 확인
        if not self.check_thrust_allocation(self.target_position):
            temp_target_position = self.find_temp_target_position()
            if temp_target_position is not None:
                self.target_position = temp_target_position
                self.get_logger().info('임시 목표 위치를 설정합니다.')
            else:
                self.get_logger().info('임시 목표 위치를 찾을 수 없습니다.')
        # 추력을 계속 할당하도록 allocate_thrust 호출 추가
        self.allocate_thrust(np.zeros(3))  # 기본값으로 delta = [0, 0, 0] 전달

        # 목표 위치와의 거리 및 오차 계산
        error = self.calculate_error(self.target_position, distance)
        
        kps = np.array([self.kp_x, self.kp_y, self.kp_psi])
        kds = np.array([self.kd_x, self.kd_y, self.kd_psi])

        Kp = np.diag(kps)
        Kd = np.diag(kds)
        self.Control.update(Kp, Kd)
        delta = self.Control.main(error, self.psi, self.dt)

        self.allocate_thrust(delta)

    def calculate_error(self, target_position, distance):
        """주어진 목표 위치와 현재 위치 간의 오차 계산"""
        error_x = target_position[0] - self.position[0]
        error_y = target_position[1] - self.position[1]
        desired_heading = np.arctan2(error_y, error_x)
        error_heading = (desired_heading - self.psi + np.pi) % (2 * np.pi) - np.pi

        msg2             = GuidanceType()
        msg2.desired_psi = round(desired_heading, 4)
        msg2.error_x     = round(error_x, 4)
        msg2.error_y     = round(error_y, 4)
        msg2.error_psi   = round(error_heading, 4)
        msg2.distance    = round(distance, 2)
        msg2.x_waypoint  = round(self.target_position[0], 4)
        msg2.y_waypoint  = round(self.target_position[1], 4)

        self.guidance_publisher.publish(msg2)

        return np.array([error_x, error_y, error_heading])
    
    def calculate_u1x_u2x(self, Fx, Fy, tau_psi, h, w):
        u1x = 0.5 * (Fx + (tau_psi + h * Fy) / w)
        u2x = 0.5 * (Fx - (tau_psi + h * Fy) / w)
        return u1x, u2x

    def calculate_ab(self, u1x, u2x, umax, thetamax):
        a1, a2 = abs(u1x) * np.tan(thetamax), np.sqrt(max(0, umax**2 - u1x**2))
        b1, b2 = abs(u2x) * np.tan(thetamax), np.sqrt(max(0, umax**2 - u2x**2))
        return min(a1, a2), min(b1, b2)

    def calculate_u1y_u2y(self, Fy, a, b):
        """
        y축 힘 Fy를 주어진 a, b 범위 내에서 u1y와 u2y로 분배하여 반환.
        할당이 불가능한 경우 (0, 0)을 반환하고, 할당 가능 여부를 함께 반환.
        """
        self.get_logger().info(f"Debug Fy: {Fy}, a: {a}, b: {b}")
        if abs(Fy) <= 2 * min(abs(a), abs(b)):
            # 할당 가능: |Fy|가 2 * min(|a|, |b|) 이하인 경우
            return 0.5 * Fy, 0.5 * Fy, True
        elif 2 * min(abs(a), abs(b)) < abs(Fy) <= abs(a) + abs(b):
            # 할당 가능: 2 * min(|a|, |b|) < |Fy| <= |a| + |b| 인 경우
            if abs(a) >= abs(b):
                u2y = np.sign(Fy) * abs(b)
                u1y = np.sign(Fy) * (abs(Fy) - abs(b))
            else:
                u1y = np.sign(Fy) * abs(a)
                u2y = np.sign(Fy) * (abs(Fy) - abs(a))
            return u1y, u2y, True
        else:
            # 할당 불가능: |Fy| > |a| + |b| 인 경우
            print("No feasible solution exists")
            return 0.0, 0.0, False

    def calculate_azimuth_angles(self, u1x, u1y, u2x, u2y, thetamax):
        theta1 = np.clip(np.arctan2(u1y, u1x), -thetamax, thetamax)
        theta2 = np.clip(np.arctan2(u2y, u2x), -thetamax, thetamax)
        return theta1, theta2
    
    def check_thrust_allocation(self, target_position):
        """주어진 목표 위치에서 추력 할당 가능 여부 확인"""
        h        = 2.373776
        w        = 1.027135
        umax     = 300.0 # 220N
        thetamax = np.deg2rad(60.0)

        error = self.calculate_error(target_position, np.linalg.norm(target_position - self.position))

        kps = np.array([self.kp_x, self.kp_y, self.kp_psi])
        kds = np.array([self.kd_x, self.kd_y, self.kd_psi])

        Kp = np.diag(kps)
        Kd = np.diag(kds)
        self.Control.update(Kp, Kd)
        delta = self.Control.main(error, self.psi, self.dt)
        Fx, Fy, tau_psi = np.clip(delta, -umax, umax)  # umax = 최대 추력 (220N 등)

        # u1x, u2x 계산 및 추력 할당 가능 여부 확인
        u1x, u2x = self.calculate_u1x_u2x(Fx, Fy, tau_psi, h, w)
        a, b = self.calculate_ab(u1x, u2x, umax, thetamax)
        _, _, feasible = self.calculate_u1y_u2y(Fy, a, b)

        return feasible  # 추력 할당 가능 여부 반환
    
    def find_temp_target_position(self):
        """임시 목표 위치를 탐색하여 반환"""
        for radius in np.arange(0, self.max_search_radius, self.search_step):
            for angle in np.linspace(0, 2 * np.pi, 12):
                temp_x = self.target_position[0] + radius * np.cos(angle)
                temp_y = self.target_position[1] + radius * np.sin(angle)
                temp_position = np.array([temp_x, temp_y])
                
                if self.check_thrust_allocation(temp_position):
                    return temp_position
        return None  # 임시 목표 위치를 찾지 못한 경우

    def allocate_thrust(self, delta):
        # delta[0]: x 방향 힘, delta[1]: y 방향 힘, delta[2]: z 방향 모멘트

        h        = 2.373776
        w        = 1.027135
        umax     = 300.0 # 220N
        umin     = -200.0
        thetamax = np.deg2rad(60.0)

        Fx, Fy, tau_psi = np.clip(delta, umin, umax)  # umax = 최대 추력 (220N 등)

        # Step 1: u1x, u2x 계산
        u1x, u2x = self.calculate_u1x_u2x(Fx, Fy, tau_psi, h, w)
        a, b     = self.calculate_ab(u1x, u2x, umax, thetamax)
        u1y, u2y, feasible = self.calculate_u1y_u2y(Fy, a, b)

        if feasible:
            # 각도 및 PWM 계산
            theta1, theta2 = self.calculate_azimuth_angles(u1x, u1y, u2x, u2y, thetamax)
            # PWM 값에 변화율 제한 추가
            pwm1, pwm2 = np.clip(np.sqrt(u1x**2 + u1y**2), umin, umax), np.clip(np.sqrt(u2x**2 + u2y**2), umin, umax)

            # azimuth 각도 변화 제한
            theta1 = np.clip(theta1, self.prev_theta1 - self.max_azimuth_change_rate * self.dt,
                            self.prev_theta1 + self.max_azimuth_change_rate * self.dt)
            theta2 = np.clip(theta2, self.prev_theta2 - self.max_azimuth_change_rate * self.dt,
                            self.prev_theta2 + self.max_azimuth_change_rate * self.dt)

            self.prev_theta1, self.prev_theta2 = theta1, theta2  # 각도 저장
            self.prev_pwm1, self.prev_pwm2 = pwm1, pwm2

            # 메시지 생성 및 퍼블리시
            self.left_pos_publisher.publish(Float64(data=-2.0*theta2))
            self.right_pos_publisher.publish(Float64(data=-2.0*theta1))
            self.left_thrust_publisher.publish(Float64(data=1.2*pwm1))
            self.right_thrust_publisher.publish(Float64(data=1.2*pwm2))

            # Publish
            msg                    = ControlType()
            msg.delta_x            = float(round(delta[0], 4))
            msg.delta_y            = float(round(delta[1], 4))
            msg.delta_psi          = round(delta[2], 4)
            msg.thruster_pwm_port  = float(round(2.0*pwm1, 2))
            msg.thruster_pwm_stbd  = float(round(2.0*pwm2, 2))
            msg.azimuth_angle_port = round(-theta2, 4)
            msg.azimuth_angle_stbd = round(-theta1, 4)

            self.control_publisher.publish(msg)

        if not feasible:
            self.get_logger().error("Thrust allocation not feasible. Publishing zero commands.")
            self.left_pos_publisher.publish(Float64(data=0.0))
            self.right_pos_publisher.publish(Float64(data=0.0))
            self.left_thrust_publisher.publish(Float64(data=-200.0))
            self.right_thrust_publisher.publish(Float64(data=-200.0))
            return


def main(args=None):
    rclpy.init(args=args)
    try:
        control_node = Control()
        control_node.get_logger().info('DP CONTROL NODE')        
        try:
            rclpy.spin(control_node)
        except KeyboardInterrupt:
            control_node.get_logger().info('Keyboard Interrupt (SIGINT)')
        finally:
            control_node.destroy_node()
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()
