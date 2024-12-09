// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wamv_msgs:msg/ControlType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__CONTROL_TYPE__BUILDER_HPP_
#define WAMV_MSGS__MSG__DETAIL__CONTROL_TYPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wamv_msgs/msg/detail/control_type__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wamv_msgs
{

namespace msg
{

namespace builder
{

class Init_ControlType_azimuth_angle_stbd
{
public:
  explicit Init_ControlType_azimuth_angle_stbd(::wamv_msgs::msg::ControlType & msg)
  : msg_(msg)
  {}
  ::wamv_msgs::msg::ControlType azimuth_angle_stbd(::wamv_msgs::msg::ControlType::_azimuth_angle_stbd_type arg)
  {
    msg_.azimuth_angle_stbd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wamv_msgs::msg::ControlType msg_;
};

class Init_ControlType_azimuth_angle_port
{
public:
  explicit Init_ControlType_azimuth_angle_port(::wamv_msgs::msg::ControlType & msg)
  : msg_(msg)
  {}
  Init_ControlType_azimuth_angle_stbd azimuth_angle_port(::wamv_msgs::msg::ControlType::_azimuth_angle_port_type arg)
  {
    msg_.azimuth_angle_port = std::move(arg);
    return Init_ControlType_azimuth_angle_stbd(msg_);
  }

private:
  ::wamv_msgs::msg::ControlType msg_;
};

class Init_ControlType_thruster_pwm_stbd
{
public:
  explicit Init_ControlType_thruster_pwm_stbd(::wamv_msgs::msg::ControlType & msg)
  : msg_(msg)
  {}
  Init_ControlType_azimuth_angle_port thruster_pwm_stbd(::wamv_msgs::msg::ControlType::_thruster_pwm_stbd_type arg)
  {
    msg_.thruster_pwm_stbd = std::move(arg);
    return Init_ControlType_azimuth_angle_port(msg_);
  }

private:
  ::wamv_msgs::msg::ControlType msg_;
};

class Init_ControlType_thruster_pwm_port
{
public:
  explicit Init_ControlType_thruster_pwm_port(::wamv_msgs::msg::ControlType & msg)
  : msg_(msg)
  {}
  Init_ControlType_thruster_pwm_stbd thruster_pwm_port(::wamv_msgs::msg::ControlType::_thruster_pwm_port_type arg)
  {
    msg_.thruster_pwm_port = std::move(arg);
    return Init_ControlType_thruster_pwm_stbd(msg_);
  }

private:
  ::wamv_msgs::msg::ControlType msg_;
};

class Init_ControlType_pwm_standard
{
public:
  explicit Init_ControlType_pwm_standard(::wamv_msgs::msg::ControlType & msg)
  : msg_(msg)
  {}
  Init_ControlType_thruster_pwm_port pwm_standard(::wamv_msgs::msg::ControlType::_pwm_standard_type arg)
  {
    msg_.pwm_standard = std::move(arg);
    return Init_ControlType_thruster_pwm_port(msg_);
  }

private:
  ::wamv_msgs::msg::ControlType msg_;
};

class Init_ControlType_delta_psi
{
public:
  explicit Init_ControlType_delta_psi(::wamv_msgs::msg::ControlType & msg)
  : msg_(msg)
  {}
  Init_ControlType_pwm_standard delta_psi(::wamv_msgs::msg::ControlType::_delta_psi_type arg)
  {
    msg_.delta_psi = std::move(arg);
    return Init_ControlType_pwm_standard(msg_);
  }

private:
  ::wamv_msgs::msg::ControlType msg_;
};

class Init_ControlType_delta_y
{
public:
  explicit Init_ControlType_delta_y(::wamv_msgs::msg::ControlType & msg)
  : msg_(msg)
  {}
  Init_ControlType_delta_psi delta_y(::wamv_msgs::msg::ControlType::_delta_y_type arg)
  {
    msg_.delta_y = std::move(arg);
    return Init_ControlType_delta_psi(msg_);
  }

private:
  ::wamv_msgs::msg::ControlType msg_;
};

class Init_ControlType_delta_x
{
public:
  explicit Init_ControlType_delta_x(::wamv_msgs::msg::ControlType & msg)
  : msg_(msg)
  {}
  Init_ControlType_delta_y delta_x(::wamv_msgs::msg::ControlType::_delta_x_type arg)
  {
    msg_.delta_x = std::move(arg);
    return Init_ControlType_delta_y(msg_);
  }

private:
  ::wamv_msgs::msg::ControlType msg_;
};

class Init_ControlType_header
{
public:
  Init_ControlType_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ControlType_delta_x header(::wamv_msgs::msg::ControlType::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ControlType_delta_x(msg_);
  }

private:
  ::wamv_msgs::msg::ControlType msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wamv_msgs::msg::ControlType>()
{
  return wamv_msgs::msg::builder::Init_ControlType_header();
}

}  // namespace wamv_msgs

#endif  // WAMV_MSGS__MSG__DETAIL__CONTROL_TYPE__BUILDER_HPP_
