// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wamv_msgs:msg/NavigationType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__NAVIGATION_TYPE__STRUCT_HPP_
#define WAMV_MSGS__MSG__DETAIL__NAVIGATION_TYPE__STRUCT_HPP_

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
# define DEPRECATED__wamv_msgs__msg__NavigationType __attribute__((deprecated))
#else
# define DEPRECATED__wamv_msgs__msg__NavigationType __declspec(deprecated)
#endif

namespace wamv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavigationType_
{
  using Type = NavigationType_<ContainerAllocator>;

  explicit NavigationType_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->psi = 0.0;
      this->u = 0.0;
      this->v = 0.0;
      this->r = 0.0;
      this->w = 0.0;
    }
  }

  explicit NavigationType_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->psi = 0.0;
      this->u = 0.0;
      this->v = 0.0;
      this->r = 0.0;
      this->w = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _psi_type =
    double;
  _psi_type psi;
  using _u_type =
    double;
  _u_type u;
  using _v_type =
    double;
  _v_type v;
  using _r_type =
    double;
  _r_type r;
  using _w_type =
    double;
  _w_type w;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__psi(
    const double & _arg)
  {
    this->psi = _arg;
    return *this;
  }
  Type & set__u(
    const double & _arg)
  {
    this->u = _arg;
    return *this;
  }
  Type & set__v(
    const double & _arg)
  {
    this->v = _arg;
    return *this;
  }
  Type & set__r(
    const double & _arg)
  {
    this->r = _arg;
    return *this;
  }
  Type & set__w(
    const double & _arg)
  {
    this->w = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wamv_msgs::msg::NavigationType_<ContainerAllocator> *;
  using ConstRawPtr =
    const wamv_msgs::msg::NavigationType_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wamv_msgs::msg::NavigationType_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wamv_msgs::msg::NavigationType_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wamv_msgs::msg::NavigationType_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wamv_msgs::msg::NavigationType_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wamv_msgs::msg::NavigationType_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wamv_msgs::msg::NavigationType_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wamv_msgs::msg::NavigationType_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wamv_msgs::msg::NavigationType_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wamv_msgs__msg__NavigationType
    std::shared_ptr<wamv_msgs::msg::NavigationType_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wamv_msgs__msg__NavigationType
    std::shared_ptr<wamv_msgs::msg::NavigationType_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavigationType_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->psi != other.psi) {
      return false;
    }
    if (this->u != other.u) {
      return false;
    }
    if (this->v != other.v) {
      return false;
    }
    if (this->r != other.r) {
      return false;
    }
    if (this->w != other.w) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavigationType_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavigationType_

// alias to use template instance with default allocator
using NavigationType =
  wamv_msgs::msg::NavigationType_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace wamv_msgs

#endif  // WAMV_MSGS__MSG__DETAIL__NAVIGATION_TYPE__STRUCT_HPP_
