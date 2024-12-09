// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wamv_msgs:msg/GuidanceType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__GUIDANCE_TYPE__BUILDER_HPP_
#define WAMV_MSGS__MSG__DETAIL__GUIDANCE_TYPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wamv_msgs/msg/detail/guidance_type__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wamv_msgs
{

namespace msg
{

namespace builder
{

class Init_GuidanceType_y_waypoint
{
public:
  explicit Init_GuidanceType_y_waypoint(::wamv_msgs::msg::GuidanceType & msg)
  : msg_(msg)
  {}
  ::wamv_msgs::msg::GuidanceType y_waypoint(::wamv_msgs::msg::GuidanceType::_y_waypoint_type arg)
  {
    msg_.y_waypoint = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wamv_msgs::msg::GuidanceType msg_;
};

class Init_GuidanceType_x_waypoint
{
public:
  explicit Init_GuidanceType_x_waypoint(::wamv_msgs::msg::GuidanceType & msg)
  : msg_(msg)
  {}
  Init_GuidanceType_y_waypoint x_waypoint(::wamv_msgs::msg::GuidanceType::_x_waypoint_type arg)
  {
    msg_.x_waypoint = std::move(arg);
    return Init_GuidanceType_y_waypoint(msg_);
  }

private:
  ::wamv_msgs::msg::GuidanceType msg_;
};

class Init_GuidanceType_distance
{
public:
  explicit Init_GuidanceType_distance(::wamv_msgs::msg::GuidanceType & msg)
  : msg_(msg)
  {}
  Init_GuidanceType_x_waypoint distance(::wamv_msgs::msg::GuidanceType::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_GuidanceType_x_waypoint(msg_);
  }

private:
  ::wamv_msgs::msg::GuidanceType msg_;
};

class Init_GuidanceType_error_psi
{
public:
  explicit Init_GuidanceType_error_psi(::wamv_msgs::msg::GuidanceType & msg)
  : msg_(msg)
  {}
  Init_GuidanceType_distance error_psi(::wamv_msgs::msg::GuidanceType::_error_psi_type arg)
  {
    msg_.error_psi = std::move(arg);
    return Init_GuidanceType_distance(msg_);
  }

private:
  ::wamv_msgs::msg::GuidanceType msg_;
};

class Init_GuidanceType_error_y
{
public:
  explicit Init_GuidanceType_error_y(::wamv_msgs::msg::GuidanceType & msg)
  : msg_(msg)
  {}
  Init_GuidanceType_error_psi error_y(::wamv_msgs::msg::GuidanceType::_error_y_type arg)
  {
    msg_.error_y = std::move(arg);
    return Init_GuidanceType_error_psi(msg_);
  }

private:
  ::wamv_msgs::msg::GuidanceType msg_;
};

class Init_GuidanceType_error_x
{
public:
  explicit Init_GuidanceType_error_x(::wamv_msgs::msg::GuidanceType & msg)
  : msg_(msg)
  {}
  Init_GuidanceType_error_y error_x(::wamv_msgs::msg::GuidanceType::_error_x_type arg)
  {
    msg_.error_x = std::move(arg);
    return Init_GuidanceType_error_y(msg_);
  }

private:
  ::wamv_msgs::msg::GuidanceType msg_;
};

class Init_GuidanceType_desired_psi
{
public:
  explicit Init_GuidanceType_desired_psi(::wamv_msgs::msg::GuidanceType & msg)
  : msg_(msg)
  {}
  Init_GuidanceType_error_x desired_psi(::wamv_msgs::msg::GuidanceType::_desired_psi_type arg)
  {
    msg_.desired_psi = std::move(arg);
    return Init_GuidanceType_error_x(msg_);
  }

private:
  ::wamv_msgs::msg::GuidanceType msg_;
};

class Init_GuidanceType_header
{
public:
  Init_GuidanceType_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GuidanceType_desired_psi header(::wamv_msgs::msg::GuidanceType::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GuidanceType_desired_psi(msg_);
  }

private:
  ::wamv_msgs::msg::GuidanceType msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wamv_msgs::msg::GuidanceType>()
{
  return wamv_msgs::msg::builder::Init_GuidanceType_header();
}

}  // namespace wamv_msgs

#endif  // WAMV_MSGS__MSG__DETAIL__GUIDANCE_TYPE__BUILDER_HPP_
