#!/usr/bin/env python3
import rclpy
import numpy as np

from rclpy.node import Node
from wamv_msgs.msg import NavigationType, ControlType, RLType
from std_msgs.msg import Header, Float64

class WAMVInfoNode(Node):
    def __init__(self):
        super().__init__('wamv_info_node')

        # Initial subscriber data
        self.left_thrust         = None
        self.right_thrust        = None
        self.guidance_data       = None
        self.navigation_data     = None
        self.ukf_navigation_data = None
        self.control_data        = None

        # subscriber
        self.fusion_nav_subscriber   = self.create_subscription(NavigationType, '/ukf_navigation', self.fusion_nav_callback, 20)
        self.navigation_subscriber   = self.create_subscription(NavigationType, '/navigation',                  self.navigation_callback,   20)
        self.left_thrust_subscriber  = self.create_subscription(Float64,        '/wamv/thrusters/left/thrust',  self.left_thrust_callback,  10)
        self.right_thrust_subscriber = self.create_subscription(Float64,        '/wamv/thrusters/right/thrust', self.right_thrust_callback, 10)
        
        # publisher
        self.wamv_info_publisher = self.create_publisher(RLType, '/wamv_info', 10)

        self.dt = 0.1

        self.timer = self.create_timer(self.dt, self.publish_wamv_info_msg)

    def left_thrust_callback(self, msg):
        self.left_thrust = msg.data

    def right_thrust_callback(self, msg):
        self.right_thrust = msg.data    
    
    def fusion_nav_callback(self, msg):
        self.ukf_navigation_data = msg
        self.ukf_x               = self.ukf_navigation_data.x
        self.ukf_y               = self.ukf_navigation_data.y
        self.ukf_psi             = self.ukf_navigation_data.psi
        self.ukf_u               = self.ukf_navigation_data.u

    def navigation_callback(self, msg):
        self.navigation_data = msg 
        self.x               = self.navigation_data.x
        self.y               = self.navigation_data.y
        self.psi             = self.navigation_data.psi
        self.u               = self.navigation_data.u

    def publish_wamv_info_msg(self):
        if self.navigation_data is None or self.left_thrust is None:
            return

        header          = Header()
        header.stamp    = self.get_clock().now().to_msg()
        header.frame_id = 'WAM-V'

        wamv_info                 = RLType()
        wamv_info.header          = header
        wamv_info.ukf_navigation  = self.ukf_navigation_data
        wamv_info.navigation      = self.navigation_data
        wamv_info.left_thrust     = self.left_thrust
        wamv_info.right_thrust    = self.right_thrust
        self.wamv_info_publisher.publish(wamv_info)

def main(args=None):
    rclpy.init(args=args)
    try:
        wamv_info_node = WAMVInfoNode()
        try:
            rclpy.spin(wamv_info_node)
        except KeyboardInterrupt:
            wamv_info_node.get_logger().info('Keyboard Interrupt (SIGINT)')
        finally:
            wamv_info_node.destroy_node()
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()
