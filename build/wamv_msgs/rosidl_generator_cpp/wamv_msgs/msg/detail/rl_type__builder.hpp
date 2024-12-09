// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wamv_msgs:msg/RLType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__RL_TYPE__BUILDER_HPP_
#define WAMV_MSGS__MSG__DETAIL__RL_TYPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wamv_msgs/msg/detail/rl_type__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wamv_msgs
{

namespace msg
{

namespace builder
{

class Init_RLType_right_thrust
{
public:
  explicit Init_RLType_right_thrust(::wamv_msgs::msg::RLType & msg)
  : msg_(msg)
  {}
  ::wamv_msgs::msg::RLType right_thrust(::wamv_msgs::msg::RLType::_right_thrust_type arg)
  {
    msg_.right_thrust = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wamv_msgs::msg::RLType msg_;
};

class Init_RLType_left_thrust
{
public:
  explicit Init_RLType_left_thrust(::wamv_msgs::msg::RLType & msg)
  : msg_(msg)
  {}
  Init_RLType_right_thrust left_thrust(::wamv_msgs::msg::RLType::_left_thrust_type arg)
  {
    msg_.left_thrust = std::move(arg);
    return Init_RLType_right_thrust(msg_);
  }

private:
  ::wamv_msgs::msg::RLType msg_;
};

class Init_RLType_navigation
{
public:
  explicit Init_RLType_navigation(::wamv_msgs::msg::RLType & msg)
  : msg_(msg)
  {}
  Init_RLType_left_thrust navigation(::wamv_msgs::msg::RLType::_navigation_type arg)
  {
    msg_.navigation = std::move(arg);
    return Init_RLType_left_thrust(msg_);
  }

private:
  ::wamv_msgs::msg::RLType msg_;
};

class Init_RLType_header
{
public:
  Init_RLType_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RLType_navigation header(::wamv_msgs::msg::RLType::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RLType_navigation(msg_);
  }

private:
  ::wamv_msgs::msg::RLType msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wamv_msgs::msg::RLType>()
{
  return wamv_msgs::msg::builder::Init_RLType_header();
}

}  // namespace wamv_msgs

#endif  // WAMV_MSGS__MSG__DETAIL__RL_TYPE__BUILDER_HPP_
