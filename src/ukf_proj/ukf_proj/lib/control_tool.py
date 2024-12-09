#!/usr/bin/env python3

import numpy as np

class NonlinearPDControl:
    def __init__(self):
        """
        비선형 PD 제어기의 초기화 메소드.
        
        Parameters:
        - Kp: 비례 이득 행렬 (3x3)
        - Kd: 미분 이득 행렬 (3x3)
        """
        self.Kp = np.eye(N=3)  # Proportional gain matrix
        self.Kd = np.eye(N=3)  # Derivative gain matrix
        self.prevError = None
        
    def update(self, kp, kd):
        '''
        update: update parameter in class
        '''
        self.kp = kp
        self.kd = kd

    def main(self, error, psi, dt):
        """
        제어 입력을 계산하는 메소드.

        Parameters:
        - eta_t: 오차 벡터 (목표 자세와 현재 자세의 차이) [x_error, y_error, psi_error] (1x3)
        - psi: 현재 방위각 (rad)
        
        Returns:
        - tau: 제어 입력 벡터 [tau_x, tau_y, tau_n] (1x3), x, y 방향의 힘과 z 방향 모멘트
        """

        J_eta = np.array([
            [np.cos(psi), -np.sin(psi), 0],
            [np.sin(psi),  np.cos(psi), 0],
            [0,            0,           1]
        ])

        if self.prevError is None:
            error_dot = np.zeros(3)
        else:
            error_dot = (error - self.prevError) / dt
        self.prevError = error

        # J(eta) 미분 행렬 dJ/dt 계산
        psi_dot = error_dot[2]  # psi의 변화율

        dJ_dt = psi_dot * np.array([
            [-np.sin(psi), -np.cos(psi), 0],
            [ np.cos(psi), -np.sin(psi), 0],
            [0,            0,           0]
        ])        

        # term1: -Kp * J(eta)^T * eta_t
        term1 = self.kp @ J_eta.T @ error

        # term2: -Kd * { J(eta)^T * eta_dot + dJ/dt * eta }
        term2 = self.kd @ (J_eta.T @ error_dot + dJ_dt @ error)

        # 최종 제어 입력 tau 계산
        tau = term1 + term2

        return tau


class PIDControl():
    '''
    PIDControl():
        Class for PID contorl.
    '''
    def __init__(self):
        '''
        __init__: initalize parameters in class
            Inputs: 
                None
        '''
        self.kp = 0.0
        self.ki = 0.0
        self.kd = 0.0
        self.prevError = None

    def update(self, kp, ki, kd):
        '''
        update: update parameter in class
        
        Inputs:
            kp (float): proportional gain for heading PID controller [-]
            
            ki (float): integral gain for heading PID controller [-]
            
            kd (float): derivative gain for heading PID controller [-]
        '''
        self.kp = kp
        self.ki = ki
        self.kd = kd
        
    def main(self, error, saturation, dt):
        '''
        main: calculate output value of class
        
        Inputs:
            error (float): deviation between desired state and state [-]
            
            saturation (float): saturate the control value such as PWM, RPM and Force  [-]
            
            dt (float): sampling time [s]
                
        Outputs:
            controlValue (float): the output value of PID controller such as PWM, RPM and Force [-]
        '''
        if self.prevError is None:
            error_dot = 0 
        else:
            error_dot = (error - self.prevError) / dt
        error_integral =+ error*dt 
        self.prevError = error
        controlValue = self.kp*error + self.ki*error_integral + self.kd*error_dot
        if saturation is None:
            pass
        else:
            if abs(controlValue) >= saturation:
                controlValue = np.sign(controlValue) * saturation

        return controlValue
    
class Smoother:
    '''
    Smoother():
        Class for smoothing the value using second order differential equation, J.-Y. Park, 2016, Design of a Safety Operational Envelope Protection System for a Submerged Body.
    '''
    def __init__(self, current):
        '''
        __init__: initalize parameters in class
            Inputs: 
                None
        '''
        self.wn          = 0.0
        self.zeta        = 0.0
        self.current_dot = 0.0
        self.current     = current
        
    def update(self, wn, zeta):
        '''
        update: update parameter in class
        
        Inputs:
            wn (float): natural frequency
            
            zeta (float): damping ratio
        '''
        self.wn   = wn
        self.zeta = zeta

    def main(self, command, dt):
        '''
        main: calcaulte output value of class
        
        Inputs:
            command (float): deviation between desired state and state [-]
            
            dt (float): sampling time [s]
                
        Outputs:
            current (float): output value of smoother [-]
            current_dot (float): first order differential value of output [-]
        '''
        current_dot2D    = self.wn**2*(command - self.current) - 2*self.zeta*self.wn*self.current_dot
        self.current_dot = self.current_dot + current_dot2D*dt
        self.current     = self.current + self.current_dot*dt
        
        return self.current
    

# def calculate_speed_reference(distance_to_waypoint, radius):
#     # 거리 기반 속도 참조 계산
#     if distance_to_waypoint > 2 * radius:
#         return maximum_speed
#     else:
#         # 거리가 줄어들수록 지수적으로 감속
#         exp_factor = np.exp(-distance_to_waypoint / radius)
#         speed = maximum_speed * exp_factor
#         return max(speed, minimum_speed)  # 최소 속도 보장

def distance_to_waypoint(position, target_position):
    return np.linalg.norm(position - target_position)
    
def check_waypoint_reached(position, target_position, radius):
    return np.linalg.norm(position - target_position) <= radius

def pwm_remapping(pwm, dead_min, dead_max, pwm_min, pwm_max):
    ''' PWM DEADZONE DELETING
    pwm      : 제어 명령 값
    dead_min : 데드존 최소값 [1476]
    dead_max : 데드존 최대값 [1528]
    pwm_min  : 제어 명령 최소값
    pwm_max  : 제어 명령 최대값
    '''
    if 1500 < pwm:
        pwm_percentage = (pwm - 1500) / (pwm_max - 1500)
        remapped_pwm = dead_max + pwm_percentage * (pwm_max - dead_max)
    elif pwm < 1500:
        pwm_percentage = (1500 - pwm) / (1500 - pwm_min)
        remapped_pwm = dead_min - pwm_percentage * (dead_min - pwm_min)
    else:
        remapped_pwm = 1500
        
    return remapped_pwm

def pwm_remapping2(pwm, dead_min, dead_max, pwm_max, pwm_min):
    if 1500 < pwm < dead_max:
        pwm_percentage = (pwm - 1500) / (pwm_max -1500)
        pwm_remap = dead_max + pwm_percentage*(pwm_max-dead_max)
    elif dead_min < pwm < 1500:
        pwm_percentage = (1500 - pwm) / (1500 - pwm_min)
        pwm_remap = dead_min - pwm_percentage*(dead_min-pwm_min)
    elif pwm > dead_max:
        pwm_remap = pwm
    elif pwm < dead_min:
        pwm_remap = pwm
    else:
        pwm_remap = 1500

    return pwm_remap


def quadratic_function_pwm(x1, x2, x3, y1, y2, y3):
    ''' Quadratic Function Curve Fitting of PWM-Error Psi
    --> Used for Autonomous contest
    x1 : error PSI [minimum] 
    x2 : 0
    x3 : error PSI [maximum]
    y1 : pwm_gf_min
    y2 : pwm_gf_max
    y3 : pwm_gf_min
    '''
    error_psi_list = np.array([x1, x2, x3])
    standard_pwm   = np.array([y1, y2, y3])

    coefficients   = np.polyfit(error_psi_list, standard_pwm, 2)

    return coefficients

def cubic_function_pwm(error_psi, x1, x3, x4, x6, y1, y2, y3, y4, y5, y6):
    ''' Curve Fitting of PWM-Error Psi
    --> Used for Death Match
    IF error_psi < 0
    x1 : error PSI [minimum]
    x3 : error PSI = 0
    x4 : error PSI = 0
    x6 : error PSI [maximum]
    y1 : parameter [pwm_gf_min]
    y2 : standard_pwm = 1500
    y3 : parameter [pwm_gf_max]
    y4 : parameter [pwm_gf_max]
    y5 : standard_pwm = 1500
    y6 : parameter [pwm_gf_min]

    x2 : average value (x1, x3)
    x5 : average value (x4, x6)
    '''
    x2 = (x1 + x3) / 2
    x5 = (x4 + x6) / 2

    if error_psi < 0:
        error_psi_list = np.array([x1, x2, x3])
        standard_pwm   = np.array([y1, y2, y3])
    else:
        error_psi_list  = np.array([x4, x5, x6])
        standard_pwm   = np.array([y4, y5, y6])

    coefficients   = np.polyfit(error_psi_list, standard_pwm, 3)
    
    return coefficients