#!/usr/bin/env python3

import numpy as np
from math import sin, cos, atan2, pi
from .gnc_tool import ssa, DTR, RTD

class LineOfSight():
    '''
    LineOfSight:
        Class for implementing Line of Sight (LOS) guidance algorithm. This class calculates the desired heading and speed towards a given waypoint.
    '''
    def __init__(self):
        '''
        __init__: initalize parameters in class
        
        Inputs: 
            position (np.array): [ x, y, psi ]
                x: x coordinate position [m] 
                y: y coordinate position [m]
                psi:  heading angle [rad]
                
            velocity (np.array): [ u, v, r ]
                u: surge velocity [m/s]
                v: sway velocity [m/s]
                r: yaw rate [rad/s]
                
            waypoint (np.array): [[ x1, y1 ], [ x2, y2 ], ...]
                x: x coordinate position of target waypoint [m]
                y: y coordinate position of target waypoint [m]
            
            i_waypoint (float): index of waypoint

            circle_of_acceptance (float): circle of acceptance for waypoint tracking
        '''
        self.position             = np.array([0.0,0.0,0.0])
        self.velocity             = np.array([0.0,0.0,0.0])
        self.waypoint             = np.array([[0.0,0.0],[0.0,0.0],[0.0,0.0],[0.0,0.0]])
        self.i_waypoint           = 0.0
        self.circle_of_acceptance = 0.0
        
    def update(self, position, velocity, waypoint, i_waypoint, circle_of_acceptance):
        '''
        update: update parameter in class
        
        Inputs: 
            position (np.array): [ x, y, psi ]
                x: x coordinate position [m] 
                y: y coordinate position [m]
                psi:  heading angle [rad]
                
            velocity (np.array): [ u, v, r ]
                u: surge velocity [m/s]
                v: sway velocity [m/s]
                r: yaw rate [rad/s]
                
            waypoint (np.array): [[ x1, y1 ], [ x2, y2 ], ...]
                x: x coordinate position of target waypoint [m]
                y: y coordinate position of target waypoint [m]
            
            i_waypoint (float): index of waypoint

            circle_of_acceptance (float): circle of acceptance for waypoint tracking
        '''
        self.position             = position
        self.velocity             = velocity
        self.waypoint             = waypoint
        self.i_waypoint           = i_waypoint
        self.circle_of_acceptance = circle_of_acceptance
        
    def main(self):
        '''
        main: calculate the LOS guidance output

        Outputs:
            distance (float): straight-line distance from the position to the waypoint

            desired_psi (float): desired heading angle to reach the waypoint

            error_psi (float): heading error, which is the difference between the desired heading and the heading

            desired_u (float): desired surge velocity

            error_u (float): velocity error, which is the difference between the desired surge velocity and surge velocity

            i_waypoint (float): index of waypoint
        '''

        # Allocation variables
        x          = self.position[0]
        y          = self.position[1]
        psi        = self.position[2] # degree
        u          = self.velocity[0]
        x_waypoint = self.waypoint[0][self.i_waypoint]
        y_waypoint = self.waypoint[1][self.i_waypoint]
        
        # Algorithm (return)
        current_waypoint = np.array([self.waypoint[0][self.i_waypoint], self.waypoint[1][self.i_waypoint]])
        self.distance    = np.linalg.norm(current_waypoint - self.position[0:2])
        self.desired_psi = np.arctan2(y_waypoint - y, x_waypoint - x)*RTD # degree
        self.error_psi   = ssa(self.desired_psi - psi) # degree
        self.desired_u   = u
        self.error_u     = self.desired_u - u

        if self.distance < self.circle_of_acceptance:
            self.i_waypoint += 1
            if self.i_waypoint == len(self.waypoint):
                self.i_waypoint = 0

class ProportionalLineOfSight():
    '''
    LineOfSight:
        Class for implementing Proportional Line of Sight (LOS) guidance algorithm. This class calculates the desired heading and speed towards a given waypoint.
    '''
    def __init__(self):
        '''
        __init__: initalize parameters in class
        
        Inputs: 
            position (np.array): [ x, y, psi ]
                x: x coordinate position [m] 
                y: y coordinate position [m]
                psi:  heading angle [rad]
                
            velocity (np.array): [ u, v, r ]
                u: surge velocity [m/s]
                v: sway velocity [m/s]
                r: yaw rate [rad/s]
                
            waypoint (np.array): [[ x1, y1 ], [ x2, y2 ], ...]
                x: x coordinate position of target waypoint [m]
                y: y coordinate position of target waypoint [m]
            
            i_waypoint (float): index of waypoint

            circle_of_acceptance (float): circle of acceptance for waypoint tracking
        '''
        self.position             = np.array([0.0,0.0,0.0])
        self.velocity             = np.array([0.0,0.0,0.0])
        self.waypoint             = np.array([[0.0,0.0],[0.0,0.0],[0.0,0.0],[0.0,0.0]])
        self.i_waypoint           = 0.0
        self.circle_of_acceptance = 0.0
        self.look_ahead_distance  = 0.0
        
    def update(self, position, velocity, waypoint, i_waypoint, circle_of_acceptance, look_ahead_distance):
        '''
        update: update parameter in class
        
        Inputs: 
            position (np.array): [ x, y, psi ]
                x: x coordinate position [m] 
                y: y coordinate position [m]
                psi:  heading angle [rad]
                
            velocity (np.array): [ u, v, r ]
                u: surge velocity [m/s]
                v: sway velocity [m/s]
                r: yaw rate [rad/s]
                
            waypoint (np.array): [[ x1, y1 ], [ x2, y2 ], ...]
                x: x coordinate position of target waypoint [m]
                y: y coordinate position of target waypoint [m]
            
            i_waypoint (float): index of waypoint

            circle_of_acceptance (float): circle of acceptance for waypoint tracking

            look_ahead_distance (float): look ahead distance for PLOS algorithm
        '''
        self.position             = position
        self.velocity             = velocity
        self.waypoint             = waypoint
        self.i_waypoint           = i_waypoint
        self.circle_of_acceptance = circle_of_acceptance
        self.look_ahead_distance  = look_ahead_distance
        
    def main(self):
        '''
        main: calculate the LOS guidance output

        Outputs:
            distance (float): straight-line distance from the position to the waypoint

            desired_psi (float): desired heading angle to reach the waypoint

            error_psi (float): heading error, which is the difference between the desired heading and the heading

            desired_u (float): desired surge velocity

            error_u (float): velocity error, which is the difference between the desired surge velocity and surge velocity

            i_waypoint (float): index of waypoint
        '''

        # Allocation variables
        x          = self.position[0]
        y          = self.position[1]
        psi        = self.position[2] # degree
        u          = self.velocity[0]
        x_waypoint = self.waypoint[0][self.i_waypoint]
        y_waypoint = self.waypoint[1][self.i_waypoint]

        if self.i_waypoint == 0:
            x_waypoint_prev = self.waypoint[0][-1]
            y_waypoint_prev = self.waypoint[1][-1]
        else:
            x_waypoint_prev = self.waypoint[0][self.i_waypoint-1]
            y_waypoint_prev = self.waypoint[1][self.i_waypoint-1]
        
        # Algorithm (return)
        current_waypoint = np.array([self.waypoint[0][self.i_waypoint], self.waypoint[1][self.i_waypoint]])
        self.distance    = np.linalg.norm( current_waypoint - self.position[0:2])
        pi_p             = atan2(y_waypoint - y_waypoint_prev, x_waypoint - x_waypoint_prev)*RTD # degree
        rotate           = np.array([[cos(pi_p), sin(pi_p)],[-sin(pi_p), cos(pi_p)]] )
        cross_track_error = np.dot(rotate, np.array([self.position[0:2] - current_waypoint]).T)
        self.desired_psi = pi_p - atan2(cross_track_error[1], self.look_ahead_distance)*RTD # degree
        self.error_psi   = ssa(self.desired_psi - psi) # degree
        self.desired_u   = u
        self.error_u     = self.desired_u - u
    
        if self.distance < self.circle_of_acceptance:
            self.i_waypoint += 1
            if self.i_waypoint == len(self.waypoint):
                self.i_waypoint = 0

class IsoscelesTriangle():
    '''
    IsoscelesTriangle:
        Class for calculating isosceles triangle waypoint that compensate for return situations, Kim et al., 2021, Formation Control of Swarming Vessels Using a Virtual Matrix Approach and ISOT Guidance Algorithm.
    '''
    
    def __init__(self):
        '''
        __init__: initalize parameters in class
        
        Inputs: 
            position (np.array): [ x, y, psi ]
                x: x coordinate position [m] 
                y: y coordinate position [m]
                psi:  heading angle [rad]
                
            velocity (np.array): [ u, v, r ]
                u: surge velocity [m/s]
                v: sway velocity [m/s]
                r: yaw rate [rad/s]
                
            waypoint (np.array): [ x, y ]
                x: x coordinate position of target waypoint [m]
                y: y coordinate position of target waypoint [m]
                
            position_virtualLeader (np.array): [ x, y, psi ]
                x: x coordinate position of virtual leader [m] 
                y: y coordinate position of virtual leader [m]
                psi:  heading angle of virtual leader [rad]
                
            velocity_virtualLeader (np.array): [ u, v, r ]
                u: surge velocity of virtual leader [m/s]
                v: sway velocity of virtual leader [m/s]
                r: yaw rate of virtual leader [rad/s]
        '''
        self.position               = np.array([0.0,0.0,0.0])
        self.velocity               = np.array([0.0,0.0,0.0])
        self.waypoint               = np.array([0.0,0.0])
        self.position_virtualLeader = np.array([0.0,0.0,0.0])
        self.velocity_virtualLeader = np.array([0.0,0.0,0.0])
        
    def update(self, position, velocity, waypoint, positionVirtualLeader, velocityVirtualLeader):
        '''
        update: update parameter in class
        
        Inputs: 
            position (np.array): [ x, y, psi ]
                x: x coordinate position [m] 
                y: y coordinate position [m]
                psi:  heading angle [rad]
                
            velocity (np.array): [ u, v, r ]
                u: surge velocity [m/s]
                v: sway velocity [m/s]
                r: yaw rate [rad/s]
                
            waypoint (np.array): [ x, y ]
                x: x coordinate position of target waypoint [m]
                y: y coordinate position of target waypoint [m]
                
            position_virtualLeader (np.array): [ x, y, psi ]
                x: x coordinate position of virtual leader [m] 
                y: y coordinate position of virtual leader [m]
                psi:  heading angle of virtual leader [rad]
                
            velocity_virtualLeader (np.array): [ u, v, r ]
                u: surge velocity of virtual leader [m/s]
                v: sway velocity of virtual leader [m/s]
                r: yaw rate of virtual leader [rad/s]
        '''
        self.position               = position
        self.velocity               = velocity
        self.waypoint               = waypoint
        self.position_virtualLeader = positionVirtualLeader
        self.velocity_virtualLeader = velocityVirtualLeader
        
    def main(self, trigger_angle, minimum_distance, desired_distance, kp_distance, kd_distance):
        '''
        main: calculate the isosceles triangle output

        Inputs:
            trigger_angle (float): threshold for acceptable heading deviation, triggers ISOT guidance when exceeded
            
            minimum_distance (float): threshold distance to waypoint, determines movement necessity

        Outputs:
            goback_flag (int): flag indicating go back situation

            modified_waypoint (np.ndarray): [ x, y ]
                x: x coordinate position of modified waypoint [m]
                y: y coordinate position of modified waypoint [m]

            distance (float): straight-line distance from the position to the waypoint

            desired_psi (float): desired heading angle to reach the waypoint

            error_psi (float): heading error, which is the difference between the desired heading and the heading

            desired_u (float): desired surge velocity

            error_u (float): velocity error, which is the difference between the desired surge velocity and surge velocity
        '''

        # Allocation variables
        x                 = self.position[0]
        y                 = self.position[1]
        psi               = self.position[2] # degree
        u                 = self.velocity[0]
        x_waypoint        = self.waypoint[0]
        y_waypoint        = self.waypoint[1]
        psi_virtualLeader = self.position_virtualLeader[2] # radian
        u_virtualLeader   = self.velocity_virtualLeader[0]
        
        # Algorithm
        self.desired_psi = np.arctan2(y_waypoint - y, x_waypoint - x)*RTD # degree
        
        if abs(ssa(psi_virtualLeader- self.desired_psi)) > trigger_angle:
            self.goback_flag = 1

            distance         = np.linalg.norm(self.waypoint - self.position[0:2])
            theta            = (-psi_virtualLeader + self.desired_psi  + 180) # degree
            rotate           =  np.array([[cos(theta), sin(theta)], [-sin(theta), cos(theta)]])
            
            self.modified_waypoint = np.dot(rotate, self.position[0:2] - self.waypoint) + self.waypoint
            self.distance          = np.linalg.norm(self.modified_waypoint - self.position[0:2])
            self.desired_psi       = np.arctan2(self.modified_waypoint[1] - y, self.modified_waypoint - x)*RTD # degree
            if self.distance > minimum_distance:
                self.desired_u = u_virtualLeader * self.distance / distance
            else:
                self.desired_psi = 0.0
                self.desired_u   = 0.0
                self.goback_flag = 2

        else:
            self.goback_flag       = 0
            self.modified_waypoint = self.waypoint
            self.distance          = np.linalg.norm(self.waypoint - self.position[0:2])
            error_distance         = self.distance - desired_distance
            error_distance_dot     = 0.0 
            self.desired_u         = kp_distance * error_distance + kd_distance * error_distance_dot 
            
        self.error_psi             = ssa(self.desired_psi - psi)
        self.error_u               = self.desired_u - u