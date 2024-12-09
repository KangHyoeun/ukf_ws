// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wamv_msgs:msg/WAMVInfo.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__WAMV_INFO__STRUCT_HPP_
#define WAMV_MSGS__MSG__DETAIL__WAMV_INFO__STRUCT_HPP_

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
// Member 'ukf_navigation'
// Member 'navigation'
#include "wamv_msgs/msg/detail/navigation_type__struct.hpp"
// Member 'guidance'
#include "wamv_msgs/msg/detail/guidance_type__struct.hpp"
// Member 'control'
#include "wamv_msgs/msg/detail/control_type__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__wamv_msgs__msg__WAMVInfo __attribute__((deprecated))
#else
# define DEPRECATED__wamv_msgs__msg__WAMVInfo __declspec(deprecated)
#endif

namespace wamv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WAMVInfo_
{
  using Type = WAMVInfo_<ContainerAllocator>;

  explicit WAMVInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    ukf_navigation(_init),
    navigation(_init),
    guidance(_init),
    control(_init)
  {
    (void)_init;
  }

  explicit WAMVInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    ukf_navigation(_alloc, _init),
    navigation(_alloc, _init),
    guidance(_alloc, _init),
    control(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _ukf_navigation_type =
    wamv_msgs::msg::NavigationType_<ContainerAllocator>;
  _ukf_navigation_type ukf_navigation;
  using _navigation_type =
    wamv_msgs::msg::NavigationType_<ContainerAllocator>;
  _navigation_type navigation;
  using _guidance_type =
    wamv_msgs::msg::GuidanceType_<ContainerAllocator>;
  _guidance_type guidance;
  using _control_type =
    wamv_msgs::msg::ControlType_<ContainerAllocator>;
  _control_type control;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__ukf_navigation(
    const wamv_msgs::msg::NavigationType_<ContainerAllocator> & _arg)
  {
    this->ukf_navigation = _arg;
    return *this;
  }
  Type & set__navigation(
    const wamv_msgs::msg::NavigationType_<ContainerAllocator> & _arg)
  {
    this->navigation = _arg;
    return *this;
  }
  Type & set__guidance(
    const wamv_msgs::msg::GuidanceType_<ContainerAllocator> & _arg)
  {
    this->guidance = _arg;
    return *this;
  }
  Type & set__control(
    const wamv_msgs::msg::ControlType_<ContainerAllocator> & _arg)
  {
    this->control = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wamv_msgs::msg::WAMVInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const wamv_msgs::msg::WAMVInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wamv_msgs::msg::WAMVInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wamv_msgs::msg::WAMVInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wamv_msgs::msg::WAMVInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wamv_msgs::msg::WAMVInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wamv_msgs::msg::WAMVInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wamv_msgs::msg::WAMVInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wamv_msgs::msg::WAMVInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wamv_msgs::msg::WAMVInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wamv_msgs__msg__WAMVInfo
    std::shared_ptr<wamv_msgs::msg::WAMVInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wamv_msgs__msg__WAMVInfo
    std::shared_ptr<wamv_msgs::msg::WAMVInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WAMVInfo_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->ukf_navigation != other.ukf_navigation) {
      return false;
    }
    if (this->navigation != other.navigation) {
      return false;
    }
    if (this->guidance != other.guidance) {
      return false;
    }
    if (this->control != other.control) {
      return false;
    }
    return true;
  }
  bool operator!=(const WAMVInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WAMVInfo_

// alias to use template instance with default allocator
using WAMVInfo =
  wamv_msgs::msg::WAMVInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace wamv_msgs

#endif  // WAMV_MSGS__MSG__DETAIL__WAMV_INFO__STRUCT_HPP_
