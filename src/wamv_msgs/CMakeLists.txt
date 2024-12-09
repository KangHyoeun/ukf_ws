cmake_minimum_required(VERSION 3.8)
project(wamv_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(std_msgs REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/NavigationType.msg"
  "msg/ControlType.msg"
  "msg/GuidanceType.msg"
  "msg/WAMVInfo.msg"
  "msg/RLType.msg"
  DEPENDENCIES builtin_interfaces std_msgs
  )
  
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)

  set(ament_cmake_copyright_FOUND TRUE)

  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
