import numpy as np
from cvxopt import matrix, solvers
from scipy.optimize import minimize

class ThrustAllocator:
    def __init__(self, umax, thetamax_deg, h, w):
        self.umax = umax  # 최대 추력
        self.thetamax = np.deg2rad(thetamax_deg)  # 최대 타각 제한 (라디안)
        self.h = h  # 선박 파라미터 h
        self.w = w  # 선박 파라미터 w

    def calculate_uix(self, X_con, Y_con, N_con):
        # u1x와 u2x 계산
        u1x = 0.5 * (X_con + (N_con + self.h * Y_con) / self.w)
        u2x = 0.5 * (X_con - (N_con + self.h * Y_con) / self.w)
        return u1x, u2x

    def calculate_uiy_limits(self, uix):
        # 최대 추력 제약 조건 적용
        thrust_limit = np.sqrt(self.umax**2 - uix**2)

        # 최대 타각 제약 조건 적용
        angle_limit = abs(uix) * np.tan(self.thetamax)
        
        # uiy의 허용 범위는 두 제약 조건의 교집합
        uiy_min = max(-thrust_limit, -angle_limit)
        uiy_max = min(thrust_limit, angle_limit)
        
        return uiy_min, uiy_max

    def allocate_thrust(self, X_con, Y_con, N_con):
        # u1x, u2x 계산
        u1x, u2x = self.calculate_uix(X_con, Y_con, N_con)

        # u1y, u2y의 제한 범위 계산
        u1y_min, u1y_max = self.calculate_uiy_limits(u1x)
        u2y_min, u2y_max = self.calculate_uiy_limits(u2x)

        # 여기에서는 제어 입력의 Ycon을 만족시키기 위해 u1y, u2y 분배 (간단한 비율 계산)
        # 가능한 u1y, u2y 범위 내에서 Y_con을 만족하도록 분배
        u1y = (Y_con / 2) if (u1y_min <= Y_con / 2 <= u1y_max) else np.clip(Y_con / 2, u1y_min, u1y_max)
        u2y = (Y_con / 2) if (u2y_min <= Y_con / 2 <= u2y_max) else np.clip(Y_con / 2, u2y_min, u2y_max)

        return u1x, u1y, u2x, u2y

# 파라미터 설정 (예시)
umax = 1500.0        # 최대 추력
thetamax_deg = 45    # 최대 타각 (도)
h = 2.0              # 선박 파라미터 h (예시 값)
w = 3.0              # 선박 파라미터 w (예시 값)

# 컨트롤 입력 설정 (예시)
X_con = 500.0        # X 방향 힘
Y_con = 200.0        # Y 방향 힘
N_con = 50.0         # 회전 모멘트

# 추력 분배 실행
allocator = ThrustAllocator(umax, thetamax_deg, h, w)
u1x, u1y, u2x, u2y = allocator.allocate_thrust(X_con, Y_con, N_con)

print("Left Thruster:", u1x, u1y)
print("Right Thruster:", u2x, u2y)


class ThrustAllocatorNonConvex:
    def __init__(self, umax, thetamax_deg, d):
        self.umax = umax  # 최대 추력
        self.thetamax = np.deg2rad(thetamax_deg)  # 최대 타각 (라디안)
        self.d = d  # 추진기 간 거리 (모멘트 팔)

    def thrust_constraints(self, u):
        # 각 추진기의 x, y 방향 추력 제한과 타각 제한 조건을 설정
        u1x, u1y, u2x, u2y = u

        constraints = []

        # 최대 추력 제약 조건
        constraints.append(u1x**2 + u1y**2 - self.umax**2)
        constraints.append(u2x**2 + u2y**2 - self.umax**2)

        # 타각 제한 제약 조건
        angle1 = np.arctan2(u1y, u1x)
        angle2 = np.arctan2(u2y, u2x)

        constraints.append(angle1 - self.thetamax)
        constraints.append(-angle1 - self.thetamax)
        constraints.append(angle2 - self.thetamax)
        constraints.append(-angle2 - self.thetamax)

        return np.array(constraints)

    def allocate(self, X_con, Y_con, Z_con):
        # 목적 함수: 추력 제곱의 합을 최소화
        def objective(u):
            u1x, u1y, u2x, u2y = u
            return u1x**2 + u1y**2 + u2x**2 + u2y**2

        # 제어 입력 조건
        def control_constraints(u):
            u1x, u1y, u2x, u2y = u
            return [
                u1x + u2x - X_con,            # X 방향 힘
                u1y + u2y - Y_con,            # Y 방향 힘
                self.d * (u2x - u1x) - Z_con  # 회전 모멘트
            ]

        # 초기값 설정
        initial_guess = [0.0, 0.0, 0.0, 0.0]

        # 제약 조건 정의
        constraints = [
            {'type': 'eq', 'fun': control_constraints},
            {'type': 'ineq', 'fun': self.thrust_constraints}
        ]

        # 최적화 실행
        result = minimize(objective, initial_guess, constraints=constraints)

        if result.success:
            u1x, u1y, u2x, u2y = result.x
            return u1x, u1y, u2x, u2y
        else:
            raise ValueError("Optimal solution not found")

# 예제 사용
umax = 1500.0  # 최대 추력
thetamax_deg = 45  # 최대 타각 제한 (deg)
d = 2.0  # 두 추진기 간 거리

allocator = ThrustAllocatorNonConvex(umax, thetamax_deg, d)

# 원하는 제어 입력 (예시 값)
X_con = 500.0
Y_con = 200.0
Z_con = 50.0

# 최적화 실행
try:
    u1x, u1y, u2x, u2y = allocator.allocate(X_con, Y_con, Z_con)
    print("Left Thruster:", u1x, u1y)
    print("Right Thruster:", u2x, u2y)
except ValueError as e:
    print("Optimization failed:", e)
