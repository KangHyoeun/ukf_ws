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
        default='/home/hyo/ukf_ws/src/ukf_proj/param/wamv_config.yaml')
    
    launch_description = LaunchDescription()

    launch_description.add_action(launch.actions.DeclareLaunchArgument(
        'param_dir',
        default_value=param_dir,
        description='Full path of parameter file'))
    
    # 노드 등록
    navigation_node = Node(
        package='ukf_proj',
        executable='navigation',
        name='navigation',
        namespace=ros_namespace,
        parameters=[param_dir],
        output='screen')
    
    ukf_node = Node(
        package='ukf_proj',
        executable='ukf',
        name='ukf',
        namespace=ros_namespace,
        parameters=[param_dir],
        output='screen')
    
    dp_control_node = Node(
        package='ukf_proj',
        executable='dp_control',
        name='dp_control',
        namespace=ros_namespace,
        parameters=[param_dir],
        output='screen')
    
    kmj_control_node = Node(
        package='ukf_proj',
        executable='kmj_control',
        name='kmj_control',
        namespace=ros_namespace,
        parameters=[param_dir],
        output='screen')
    
    wamv_info_node = Node(
        package='ukf_proj',
        executable='wamv_info',
        name='wamv_info',
        namespace=ros_namespace,
        parameters=[param_dir],
        output='screen')
    
    # 등록된 노드 실행
    launch_description.add_action(kmj_control_node)
    launch_description.add_action(navigation_node)
    # launch_description.add_action(ukf_node)
    launch_description.add_action(wamv_info_node)
    return launch_description