#!/usr/bin/env python3

import os
import launch 
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # .bashrc 설정된 ROS_NAMESPACE 사용
    ros_namespace = os.environ.get('ROS_NAMESPACE', 'default_namespace')

    # yaml 파일 위치 지정
    param_dir = LaunchConfiguration(
        'param_dir',
        default='/home/hyo/dp_ws/src/dprl/param/wamv_config.yaml')
    
    launch_description = LaunchDescription()

    launch_description.add_action(launch.actions.DeclareLaunchArgument(
        'param_dir',
        default_value=param_dir,
        description='Full path of parameter file'))
    
    # 노드 등록
    navigation_node = Node(
        package='dprl',
        executable='velocity_calculator',
        name='velocity_calculator',
        namespace=ros_namespace,
        parameters=[param_dir],
        output='screen')
    
    rl_control_node = Node(
        package='dprl',
        executable='pubsub',
        name='pubsub',
        namespace=ros_namespace,
        parameters=[param_dir],
        output='screen')
    
    wamv_info_node = Node(
        package='dprl',
        executable='wamv_info',
        name='wamv_info',
        namespace=ros_namespace,
        parameters=[param_dir],
        output='screen')
    
    # 등록된 노드 실행
    launch_description.add_action(rl_control_node)
    launch_description.add_action(navigation_node)
    launch_description.add_action(wamv_info_node)
    return launch_description