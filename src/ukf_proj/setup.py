from setuptools import find_packages, setup
import os
import glob
package_name = 'ukf_proj'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob.glob(os.path.join('launch', '*launch.py'))),
        ('share/' + package_name + '/param', glob.glob(os.path.join('param', '*.yaml'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='hyo',
    maintainer_email='hilucy00@pukyong.ac.kr',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'dp_control  = ukf_proj.dp_control:main',
            'kmj_control = ukf_proj.kmj_control:main',
            'ukf         = ukf_proj.ukf:main',
            'navigation  = ukf_proj.navigation:main',
            'wamv_info   = ukf_proj.wamv_info:main',
        ],
    },
)
