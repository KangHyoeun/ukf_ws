// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wamv_msgs:msg/RLType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__RL_TYPE__STRUCT_HPP_
#define WAMV_MSGS__MSG__DETAIL__RL_TYPE__STRUCT_HPP_

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
// Member 'navigation'
#include "wamv_msgs/msg/detail/navigation_type__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__wamv_msgs__msg__RLType __attribute__((deprecated))
#else
# define DEPRECATED__wamv_msgs__msg__RLType __declspec(deprecated)
#endif

namespace wamv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RLType_
{
  using Type = RLType_<ContainerAllocator>;

  explicit RLType_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    navigation(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_thrust = 0.0;
      this->right_thrust = 0.0;
    }
  }

  explicit RLType_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    navigation(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_thrust = 0.0;
      this->right_thrust = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _navigation_type =
    wamv_msgs::msg::NavigationType_<ContainerAllocator>;
  _navigation_type navigation;
  using _left_thrust_type =
    double;
  _left_thrust_type left_thrust;
  using _right_thrust_type =
    double;
  _right_thrust_type right_thrust;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__navigation(
    const wamv_msgs::msg::NavigationType_<ContainerAllocator> & _arg)
  {
    this->navigation = _arg;
    return *this;
  }
  Type & set__left_thrust(
    const double & _arg)
  {
    this->left_thrust = _arg;
    return *this;
  }
  Type & set__right_thrust(
    const double & _arg)
  {
    this->right_thrust = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wamv_msgs::msg::RLType_<ContainerAllocator> *;
  using ConstRawPtr =
    const wamv_msgs::msg::RLType_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wamv_msgs::msg::RLType_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wamv_msgs::msg::RLType_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wamv_msgs::msg::RLType_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wamv_msgs::msg::RLType_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wamv_msgs::msg::RLType_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wamv_msgs::msg::RLType_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wamv_msgs::msg::RLType_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wamv_msgs::msg::RLType_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wamv_msgs__msg__RLType
    std::shared_ptr<wamv_msgs::msg::RLType_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wamv_msgs__msg__RLType
    std::shared_ptr<wamv_msgs::msg::RLType_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RLType_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->navigation != other.navigation) {
      return false;
    }
    if (this->left_thrust != other.left_thrust) {
      return false;
    }
    if (this->right_thrust != other.right_thrust) {
      return false;
    }
    return true;
  }
  bool operator!=(const RLType_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RLType_

// alias to use template instance with default allocator
using RLType =
  wamv_msgs::msg::RLType_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace wamv_msgs

#endif  // WAMV_MSGS__MSG__DETAIL__RL_TYPE__STRUCT_HPP_
