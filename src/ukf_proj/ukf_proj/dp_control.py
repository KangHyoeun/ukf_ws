#!/usr/bin/env python3
"""
dp_control.py: 
    Class for the DP control of the USV. only psi_control.

Author: Hyo-Eun Kang 
Data  : 2024.10.
"""
import rclpy
from rclpy.node import Node

import numpy as np
import time 

from wamv_msgs.msg import NavigationType, ControlType, GuidanceType
from std_msgs.msg import Float64

from .lib.gnc_tool import saturation, ssa, DTR, RTD
from .lib.control_tool import PIDControl, Smoother, distance_to_waypoint


class Control(Node):
    def __init__(self):
        super().__init__('dp_control_node')
        
        # Initial subscriber data
        self.navigation_data    = None
        self.target_position    = np.zeros(2)
        self.target_psi         = 0.0 # deg
        self.desired_psi        = None
        self.desired_u          = None
        self.error_psi          = None
        self.error_u            = None
        self.distance           = None
        self.x_waypoint         = None
        self.y_waypoint         = None

        # 상태 플래그
        self.in_position_mode   = False

        # 시간 카운트
        self.arrival_time       = None
        self.reverse_start_time = None

        # Subscriber
        self.navigation_subscriber = self.create_subscription(NavigationType, '/navigation', self.navigation_callback, 20)
        self.wpx_subscriber        = self.create_subscription(Float64, '/x_waypoint', self.wpx_callback, 10)
        self.wpy_subscriber        = self.create_subscription(Float64, '/y_waypoint', self.wpy_callback, 10)

        # Publisher 
        self.guidance_publisher     = self.create_publisher(GuidanceType, '/guidance', 10)
        self.control_publisher      = self.create_publisher(ControlType, '/control', 10)
        self.left_pos_publisher     = self.create_publisher(Float64, '/wamv/thrusters/left/pos',     10)
        self.left_thrust_publisher  = self.create_publisher(Float64, '/wamv/thrusters/left/thrust',  10)
        self.right_pos_publisher    = self.create_publisher(Float64, '/wamv/thrusters/right/pos',    10)
        self.right_thrust_publisher = self.create_publisher(Float64, '/wamv/thrusters/right/thrust', 10)

        # Allocation class input data
        self.dt         = 0.1
        
        # Get Parameter
        self.declare_parameter('kp_psi', 8.0)
        self.declare_parameter('ki_psi', 4.0)
        self.declare_parameter('kd_psi', 2.0)
        self.declare_parameter('kp_back', 2.0)
        self.declare_parameter('ki_back', 0.0)
        self.declare_parameter('kd_back', 1.0)
        self.declare_parameter('saturation_psi', 500)
        self.declare_parameter('kp_turn', 10.0)
        self.declare_parameter('ki_turn', 0.0)
        self.declare_parameter('kd_turn', 0.0)
        self.declare_parameter('saturation_turn', 200)
        self.declare_parameter('thruster_pwm', 1000)
        self.declare_parameter('thruster_pwm_min', 0)
        self.declare_parameter('thruster_pwm_max', 2300)
        self.get_param()
        
        # Set class
        self.forwardControl     = PIDControl()
        self.backwardControl    = PIDControl()
        self.turningControl     = PIDControl()
        self.pwmSmootherPort    = Smoother(self.thruster_pwm)
        self.pwmSmootherStbd    = Smoother(self.thruster_pwm)

        # Set timer
        self.timer = self.create_timer(self.dt, self.publish_control_msg)

    def wpx_callback(self, msg):
        self.x_waypoint = msg.data

    
    def wpy_callback(self, msg):
        self.y_waypoint = msg.data


    def navigation_callback(self, msg):
        self.navigation_data = msg
        self.x   = self.navigation_data.x
        self.y   = self.navigation_data.y
        self.psi = self.navigation_data.psi
        self.u   = self.navigation_data.u
        self.r   = self.navigation_data.r

        self.position = np.array([self.x, self.y])
        
    def get_param(self):
        self.kp_psi           = self.get_parameter('kp_psi').value
        self.ki_psi           = self.get_parameter('ki_psi').value
        self.kd_psi           = self.get_parameter('kd_psi').value
        self.kp_back          = self.get_parameter('kp_back').value
        self.ki_back          = self.get_parameter('ki_back').value
        self.kd_back          = self.get_parameter('kd_back').value
        self.saturation_psi   = self.get_parameter('saturation_psi').value
        self.kp_turn          = self.get_parameter('kp_turn').value
        self.ki_turn          = self.get_parameter('ki_turn').value
        self.kd_turn          = self.get_parameter('kd_turn').value
        self.saturation_turn  = self.get_parameter('saturation_turn').value
        self.thruster_pwm     = self.get_parameter('thruster_pwm').value
        self.thruster_pwm_min = self.get_parameter('thruster_pwm_min').value
        self.thruster_pwm_max = self.get_parameter('thruster_pwm_max').value
        # self.get_logger().info(f"PID parameters - kp: {self.kp_psi}, ki: {self.ki_psi}, kd: {self.kd_psi}, saturation: {self.saturation_psi}")
        
    def publish_control_msg(self):
        # self.get_logger().info(self.navigation_data)

        if self.navigation_data is None or self.x_waypoint is None or self.y_waypoint is None:
            self.get_logger().info(f'check the goal and navigation data!', once = True)
            return
        
        # Get parameter
        self.get_param()
        
        # Update class
        self.forwardControl.update(self.kp_psi, self.ki_psi, self.kd_psi)
        self.backwardControl.update(self.kp_back, self.ki_back, self.kd_back)
        self.turningControl.update(self.kp_turn, self.ki_turn, self.kd_turn)

        # main
        self.get_logger().info('WAM-V CONTROL START', once = True)

        self.target_position = np.array([self.x_waypoint, self.y_waypoint])
        self.distance    = np.linalg.norm(self.target_position - self.position)
        delta_psi = 0.0
        
        ## 목표 위치로 이동
        if not self.in_position_mode:

            if self.distance >= 10.0: # 전진 기동
                self.desired_psi = np.rad2deg(np.arctan2(self.y_waypoint - self.y, self.x_waypoint - self.x))
                self.error_psi   = ssa(self.desired_psi - self.psi)

                if self.error_psi >= 90.0: # 후진 기동
                    thruster_pwm_port = -100.0
                    thruster_pwm_stbd = -100.0

                else:
                    delta_psi         = self.forwardControl.main(self.error_psi, None, self.dt)
                    thruster_pwm_port = float(saturation(self.thruster_pwm - delta_psi, self.thruster_pwm_min, self.thruster_pwm_max))
                    thruster_pwm_stbd = float(saturation(self.thruster_pwm + delta_psi, self.thruster_pwm_min, self.thruster_pwm_max))
            else:
                thruster_pwm_port     = 0.0
                thruster_pwm_stbd     = 0.0
                self.in_position_mode = True
        else:          
            self.desired_psi  = self.target_psi
            self.error_psi    = ssa(self.desired_psi - self.psi)
            delta_psi         = self.turningControl.main(self.error_psi, None, self.dt)
            self.thruster_pwm = 100.0 # 위치 고정 시 작은 추진력으로 유지
            thruster_pwm_port = float(saturation(self.thruster_pwm - delta_psi, self.thruster_pwm_min, self.thruster_pwm_max))
            thruster_pwm_stbd = float(saturation(self.thruster_pwm + delta_psi, self.thruster_pwm_min, self.thruster_pwm_max))

        if self.distance <= 5.0 and abs(self.error_psi) <= 5.0:
            time.sleep(10.0)
            self.timer.cancel()
            time.sleep(0.1)
            self.destroy_node()
            time.sleep(0.1)
            rclpy.shutdown()
    
        # Publish
        msg                    = ControlType()
        msg.delta_psi          = round(delta_psi, 4)
        msg.pwm_standard       = float(round(self.thruster_pwm, 2))
        msg.thruster_pwm_port  = float(round(thruster_pwm_port, 2))
        msg.thruster_pwm_stbd  = float(round(thruster_pwm_stbd, 2))

        msg2             = GuidanceType()
        msg2.desired_psi = round(self.desired_psi, 4)
        msg2.error_psi   = round(self.error_psi, 4)
        msg2.distance    = round(self.distance, 2)
        msg2.x_waypoint  = round(self.x_waypoint, 4)
        msg2.y_waypoint  = round(self.y_waypoint, 4)

        self.guidance_publisher.publish(msg2)
        self.control_publisher.publish(msg)
        
        # 퍼블리시할 메시지 생성
        port_angle_msg = Float64(data = 0.0)
        stbd_angle_msg = Float64(data = 0.0) 
        port_pwm_msg = Float64(data = thruster_pwm_port)
        stbd_pwm_msg = Float64(data = thruster_pwm_stbd)

        # publish
        self.left_pos_publisher.publish(port_angle_msg)
        self.left_thrust_publisher.publish(port_pwm_msg)
        self.right_pos_publisher.publish(stbd_angle_msg)
        self.right_thrust_publisher.publish(stbd_pwm_msg)


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
