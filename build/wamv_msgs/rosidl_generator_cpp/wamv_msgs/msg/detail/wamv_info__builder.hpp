// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wamv_msgs:msg/WAMVInfo.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__WAMV_INFO__BUILDER_HPP_
#define WAMV_MSGS__MSG__DETAIL__WAMV_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wamv_msgs/msg/detail/wamv_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wamv_msgs
{

namespace msg
{

namespace builder
{

class Init_WAMVInfo_control
{
public:
  explicit Init_WAMVInfo_control(::wamv_msgs::msg::WAMVInfo & msg)
  : msg_(msg)
  {}
  ::wamv_msgs::msg::WAMVInfo control(::wamv_msgs::msg::WAMVInfo::_control_type arg)
  {
    msg_.control = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wamv_msgs::msg::WAMVInfo msg_;
};

class Init_WAMVInfo_guidance
{
public:
  explicit Init_WAMVInfo_guidance(::wamv_msgs::msg::WAMVInfo & msg)
  : msg_(msg)
  {}
  Init_WAMVInfo_control guidance(::wamv_msgs::msg::WAMVInfo::_guidance_type arg)
  {
    msg_.guidance = std::move(arg);
    return Init_WAMVInfo_control(msg_);
  }

private:
  ::wamv_msgs::msg::WAMVInfo msg_;
};

class Init_WAMVInfo_navigation
{
public:
  explicit Init_WAMVInfo_navigation(::wamv_msgs::msg::WAMVInfo & msg)
  : msg_(msg)
  {}
  Init_WAMVInfo_guidance navigation(::wamv_msgs::msg::WAMVInfo::_navigation_type arg)
  {
    msg_.navigation = std::move(arg);
    return Init_WAMVInfo_guidance(msg_);
  }

private:
  ::wamv_msgs::msg::WAMVInfo msg_;
};

class Init_WAMVInfo_ukf_navigation
{
public:
  explicit Init_WAMVInfo_ukf_navigation(::wamv_msgs::msg::WAMVInfo & msg)
  : msg_(msg)
  {}
  Init_WAMVInfo_navigation ukf_navigation(::wamv_msgs::msg::WAMVInfo::_ukf_navigation_type arg)
  {
    msg_.ukf_navigation = std::move(arg);
    return Init_WAMVInfo_navigation(msg_);
  }

private:
  ::wamv_msgs::msg::WAMVInfo msg_;
};

class Init_WAMVInfo_header
{
public:
  Init_WAMVInfo_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WAMVInfo_ukf_navigation header(::wamv_msgs::msg::WAMVInfo::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_WAMVInfo_ukf_navigation(msg_);
  }

private:
  ::wamv_msgs::msg::WAMVInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wamv_msgs::msg::WAMVInfo>()
{
  return wamv_msgs::msg::builder::Init_WAMVInfo_header();
}

}  // namespace wamv_msgs

#endif  // WAMV_MSGS__MSG__DETAIL__WAMV_INFO__BUILDER_HPP_
