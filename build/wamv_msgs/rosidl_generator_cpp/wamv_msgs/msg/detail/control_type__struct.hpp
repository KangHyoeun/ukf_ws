// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wamv_msgs:msg/ControlType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__CONTROL_TYPE__STRUCT_HPP_
#define WAMV_MSGS__MSG__DETAIL__CONTROL_TYPE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__wamv_msgs__msg__ControlType __attribute__((deprecated))
#else
# define DEPRECATED__wamv_msgs__msg__ControlType __declspec(deprecated)
#endif

namespace wamv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ControlType_
{
  using Type = ControlType_<ContainerAllocator>;

  explicit ControlType_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->delta_x = 0.0;
      this->delta_y = 0.0;
      this->delta_psi = 0.0;
      this->pwm_standard = 0.0;
      this->thruster_pwm_port = 0.0;
      this->thruster_pwm_stbd = 0.0;
      this->azimuth_angle_port = 0.0;
      this->azimuth_angle_stbd = 0.0;
    }
  }

  explicit ControlType_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->delta_x = 0.0;
      this->delta_y = 0.0;
      this->delta_psi = 0.0;
      this->pwm_standard = 0.0;
      this->thruster_pwm_port = 0.0;
      this->thruster_pwm_stbd = 0.0;
      this->azimuth_angle_port = 0.0;
      this->azimuth_angle_stbd = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _delta_x_type =
    double;
  _delta_x_type delta_x;
  using _delta_y_type =
    double;
  _delta_y_type delta_y;
  using _delta_psi_type =
    double;
  _delta_psi_type delta_psi;
  using _pwm_standard_type =
    double;
  _pwm_standard_type pwm_standard;
  using _thruster_pwm_port_type =
    double;
  _thruster_pwm_port_type thruster_pwm_port;
  using _thruster_pwm_stbd_type =
    double;
  _thruster_pwm_stbd_type thruster_pwm_stbd;
  using _azimuth_angle_port_type =
    double;
  _azimuth_angle_port_type azimuth_angle_port;
  using _azimuth_angle_stbd_type =
    double;
  _azimuth_angle_stbd_type azimuth_angle_stbd;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__delta_x(
    const double & _arg)
  {
    this->delta_x = _arg;
    return *this;
  }
  Type & set__delta_y(
    const double & _arg)
  {
    this->delta_y = _arg;
    return *this;
  }
  Type & set__delta_psi(
    const double & _arg)
  {
    this->delta_psi = _arg;
    return *this;
  }
  Type & set__pwm_standard(
    const double & _arg)
  {
    this->pwm_standard = _arg;
    return *this;
  }
  Type & set__thruster_pwm_port(
    const double & _arg)
  {
    this->thruster_pwm_port = _arg;
    return *this;
  }
  Type & set__thruster_pwm_stbd(
    const double & _arg)
  {
    this->thruster_pwm_stbd = _arg;
    return *this;
  }
  Type & set__azimuth_angle_port(
    const double & _arg)
  {
    this->azimuth_angle_port = _arg;
    return *this;
  }
  Type & set__azimuth_angle_stbd(
    const double & _arg)
  {
    this->azimuth_angle_stbd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wamv_msgs::msg::ControlType_<ContainerAllocator> *;
  using ConstRawPtr =
    const wamv_msgs::msg::ControlType_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wamv_msgs::msg::ControlType_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wamv_msgs::msg::ControlType_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wamv_msgs::msg::ControlType_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wamv_msgs::msg::ControlType_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wamv_msgs::msg::ControlType_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wamv_msgs::msg::ControlType_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wamv_msgs::msg::ControlType_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wamv_msgs::msg::ControlType_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wamv_msgs__msg__ControlType
    std::shared_ptr<wamv_msgs::msg::ControlType_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wamv_msgs__msg__ControlType
    std::shared_ptr<wamv_msgs::msg::ControlType_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ControlType_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->delta_x != other.delta_x) {
      return false;
    }
    if (this->delta_y != other.delta_y) {
      return false;
    }
    if (this->delta_psi != other.delta_psi) {
      return false;
    }
    if (this->pwm_standard != other.pwm_standard) {
      return false;
    }
    if (this->thruster_pwm_port != other.thruster_pwm_port) {
      return false;
    }
    if (this->thruster_pwm_stbd != other.thruster_pwm_stbd) {
      return false;
    }
    if (this->azimuth_angle_port != other.azimuth_angle_port) {
      return false;
    }
    if (this->azimuth_angle_stbd != other.azimuth_angle_stbd) {
      return false;
    }
    return true;
  }
  bool operator!=(const ControlType_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ControlType_

// alias to use template instance with default allocator
using ControlType =
  wamv_msgs::msg::ControlType_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace wamv_msgs

#endif  // WAMV_MSGS__MSG__DETAIL__CONTROL_TYPE__STRUCT_HPP_
