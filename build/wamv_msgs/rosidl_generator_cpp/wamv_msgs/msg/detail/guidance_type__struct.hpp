// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wamv_msgs:msg/GuidanceType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__GUIDANCE_TYPE__STRUCT_HPP_
#define WAMV_MSGS__MSG__DETAIL__GUIDANCE_TYPE__STRUCT_HPP_

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
# define DEPRECATED__wamv_msgs__msg__GuidanceType __attribute__((deprecated))
#else
# define DEPRECATED__wamv_msgs__msg__GuidanceType __declspec(deprecated)
#endif

namespace wamv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GuidanceType_
{
  using Type = GuidanceType_<ContainerAllocator>;

  explicit GuidanceType_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->desired_psi = 0.0;
      this->error_x = 0.0;
      this->error_y = 0.0;
      this->error_psi = 0.0;
      this->distance = 0.0;
      this->x_waypoint = 0.0;
      this->y_waypoint = 0.0;
    }
  }

  explicit GuidanceType_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->desired_psi = 0.0;
      this->error_x = 0.0;
      this->error_y = 0.0;
      this->error_psi = 0.0;
      this->distance = 0.0;
      this->x_waypoint = 0.0;
      this->y_waypoint = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _desired_psi_type =
    double;
  _desired_psi_type desired_psi;
  using _error_x_type =
    double;
  _error_x_type error_x;
  using _error_y_type =
    double;
  _error_y_type error_y;
  using _error_psi_type =
    double;
  _error_psi_type error_psi;
  using _distance_type =
    double;
  _distance_type distance;
  using _x_waypoint_type =
    double;
  _x_waypoint_type x_waypoint;
  using _y_waypoint_type =
    double;
  _y_waypoint_type y_waypoint;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__desired_psi(
    const double & _arg)
  {
    this->desired_psi = _arg;
    return *this;
  }
  Type & set__error_x(
    const double & _arg)
  {
    this->error_x = _arg;
    return *this;
  }
  Type & set__error_y(
    const double & _arg)
  {
    this->error_y = _arg;
    return *this;
  }
  Type & set__error_psi(
    const double & _arg)
  {
    this->error_psi = _arg;
    return *this;
  }
  Type & set__distance(
    const double & _arg)
  {
    this->distance = _arg;
    return *this;
  }
  Type & set__x_waypoint(
    const double & _arg)
  {
    this->x_waypoint = _arg;
    return *this;
  }
  Type & set__y_waypoint(
    const double & _arg)
  {
    this->y_waypoint = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wamv_msgs::msg::GuidanceType_<ContainerAllocator> *;
  using ConstRawPtr =
    const wamv_msgs::msg::GuidanceType_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wamv_msgs::msg::GuidanceType_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wamv_msgs::msg::GuidanceType_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wamv_msgs::msg::GuidanceType_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wamv_msgs::msg::GuidanceType_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wamv_msgs::msg::GuidanceType_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wamv_msgs::msg::GuidanceType_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wamv_msgs::msg::GuidanceType_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wamv_msgs::msg::GuidanceType_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wamv_msgs__msg__GuidanceType
    std::shared_ptr<wamv_msgs::msg::GuidanceType_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wamv_msgs__msg__GuidanceType
    std::shared_ptr<wamv_msgs::msg::GuidanceType_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GuidanceType_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->desired_psi != other.desired_psi) {
      return false;
    }
    if (this->error_x != other.error_x) {
      return false;
    }
    if (this->error_y != other.error_y) {
      return false;
    }
    if (this->error_psi != other.error_psi) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    if (this->x_waypoint != other.x_waypoint) {
      return false;
    }
    if (this->y_waypoint != other.y_waypoint) {
      return false;
    }
    return true;
  }
  bool operator!=(const GuidanceType_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GuidanceType_

// alias to use template instance with default allocator
using GuidanceType =
  wamv_msgs::msg::GuidanceType_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace wamv_msgs

#endif  // WAMV_MSGS__MSG__DETAIL__GUIDANCE_TYPE__STRUCT_HPP_
