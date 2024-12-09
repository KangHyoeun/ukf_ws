#!/usr/bin/env python3

import numpy as np
from math import sin, cos, pi

DTR = pi/180 
RTD = 180/pi

def ssa(angle):
    """
    angle (float) = ssa(angle) returns the smallest-signed angle in [ -180, 180 ]
    """
    angle = (angle + 180) % (2 * 180) - 180
    if angle > 180:
        angle -= 360
    elif angle < -180:
        angle += 360
    return angle

def saturation(value, min_value, max_value):
    """
    x (float) = sat(value, min_value, max_value) saturates a signal x such that min_value <= min_value <= max_value
    """
    if value > max_value: 
        outputData = max_value
    elif value < min_value: 
        outputData =min_value
    else:
        outputData =value

    return outputData

def quaternion_to_euler(w, x, y, z):
    """
    Convert a quaternion into euler angles (pitch, roll, yaw)
    """
    # roll (x-axis rotation)
    sinr_cosp = 2 * (w * x + y * z)
    cosr_cosp = 1 - 2 * (x * x + y * y)
    roll = np.arctan2(sinr_cosp, cosr_cosp)

    # pitch (y-axis rotation)
    sinp = 2 * (w * y - z * x)
    if np.abs(sinp) >= 1:
        pitch = np.pi / 2 * np.sign(sinp) # use 90 degrees if out of range
    else:
        pitch = np.arcsin(sinp)

    # yaw (z-axis rotation)
    siny_cosp = 2 * (w * z + x * y)
    cosy_cosp = 1 - 2 * (y * y + z * z)
    yaw = np.arctan2(siny_cosp, cosy_cosp)

    return roll, pitch, yaw  # in radians
