// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wamv_msgs:msg/NavigationType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__NAVIGATION_TYPE__BUILDER_HPP_
#define WAMV_MSGS__MSG__DETAIL__NAVIGATION_TYPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wamv_msgs/msg/detail/navigation_type__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wamv_msgs
{

namespace msg
{

namespace builder
{

class Init_NavigationType_w
{
public:
  explicit Init_NavigationType_w(::wamv_msgs::msg::NavigationType & msg)
  : msg_(msg)
  {}
  ::wamv_msgs::msg::NavigationType w(::wamv_msgs::msg::NavigationType::_w_type arg)
  {
    msg_.w = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wamv_msgs::msg::NavigationType msg_;
};

class Init_NavigationType_r
{
public:
  explicit Init_NavigationType_r(::wamv_msgs::msg::NavigationType & msg)
  : msg_(msg)
  {}
  Init_NavigationType_w r(::wamv_msgs::msg::NavigationType::_r_type arg)
  {
    msg_.r = std::move(arg);
    return Init_NavigationType_w(msg_);
  }

private:
  ::wamv_msgs::msg::NavigationType msg_;
};

class Init_NavigationType_v
{
public:
  explicit Init_NavigationType_v(::wamv_msgs::msg::NavigationType & msg)
  : msg_(msg)
  {}
  Init_NavigationType_r v(::wamv_msgs::msg::NavigationType::_v_type arg)
  {
    msg_.v = std::move(arg);
    return Init_NavigationType_r(msg_);
  }

private:
  ::wamv_msgs::msg::NavigationType msg_;
};

class Init_NavigationType_u
{
public:
  explicit Init_NavigationType_u(::wamv_msgs::msg::NavigationType & msg)
  : msg_(msg)
  {}
  Init_NavigationType_v u(::wamv_msgs::msg::NavigationType::_u_type arg)
  {
    msg_.u = std::move(arg);
    return Init_NavigationType_v(msg_);
  }

private:
  ::wamv_msgs::msg::NavigationType msg_;
};

class Init_NavigationType_psi
{
public:
  explicit Init_NavigationType_psi(::wamv_msgs::msg::NavigationType & msg)
  : msg_(msg)
  {}
  Init_NavigationType_u psi(::wamv_msgs::msg::NavigationType::_psi_type arg)
  {
    msg_.psi = std::move(arg);
    return Init_NavigationType_u(msg_);
  }

private:
  ::wamv_msgs::msg::NavigationType msg_;
};

class Init_NavigationType_y
{
public:
  explicit Init_NavigationType_y(::wamv_msgs::msg::NavigationType & msg)
  : msg_(msg)
  {}
  Init_NavigationType_psi y(::wamv_msgs::msg::NavigationType::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_NavigationType_psi(msg_);
  }

private:
  ::wamv_msgs::msg::NavigationType msg_;
};

class Init_NavigationType_x
{
public:
  explicit Init_NavigationType_x(::wamv_msgs::msg::NavigationType & msg)
  : msg_(msg)
  {}
  Init_NavigationType_y x(::wamv_msgs::msg::NavigationType::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_NavigationType_y(msg_);
  }

private:
  ::wamv_msgs::msg::NavigationType msg_;
};

class Init_NavigationType_header
{
public:
  Init_NavigationType_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigationType_x header(::wamv_msgs::msg::NavigationType::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NavigationType_x(msg_);
  }

private:
  ::wamv_msgs::msg::NavigationType msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wamv_msgs::msg::NavigationType>()
{
  return wamv_msgs::msg::builder::Init_NavigationType_header();
}

}  // namespace wamv_msgs

#endif  // WAMV_MSGS__MSG__DETAIL__NAVIGATION_TYPE__BUILDER_HPP_
