// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wamv_msgs:msg/ControlType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__CONTROL_TYPE__TRAITS_HPP_
#define WAMV_MSGS__MSG__DETAIL__CONTROL_TYPE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wamv_msgs/msg/detail/control_type__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace wamv_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ControlType & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: delta_x
  {
    out << "delta_x: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_x, out);
    out << ", ";
  }

  // member: delta_y
  {
    out << "delta_y: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_y, out);
    out << ", ";
  }

  // member: delta_psi
  {
    out << "delta_psi: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_psi, out);
    out << ", ";
  }

  // member: pwm_standard
  {
    out << "pwm_standard: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_standard, out);
    out << ", ";
  }

  // member: thruster_pwm_port
  {
    out << "thruster_pwm_port: ";
    rosidl_generator_traits::value_to_yaml(msg.thruster_pwm_port, out);
    out << ", ";
  }

  // member: thruster_pwm_stbd
  {
    out << "thruster_pwm_stbd: ";
    rosidl_generator_traits::value_to_yaml(msg.thruster_pwm_stbd, out);
    out << ", ";
  }

  // member: azimuth_angle_port
  {
    out << "azimuth_angle_port: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth_angle_port, out);
    out << ", ";
  }

  // member: azimuth_angle_stbd
  {
    out << "azimuth_angle_stbd: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth_angle_stbd, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ControlType & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: delta_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_x: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_x, out);
    out << "\n";
  }

  // member: delta_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_y: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_y, out);
    out << "\n";
  }

  // member: delta_psi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_psi: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_psi, out);
    out << "\n";
  }

  // member: pwm_standard
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pwm_standard: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_standard, out);
    out << "\n";
  }

  // member: thruster_pwm_port
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "thruster_pwm_port: ";
    rosidl_generator_traits::value_to_yaml(msg.thruster_pwm_port, out);
    out << "\n";
  }

  // member: thruster_pwm_stbd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "thruster_pwm_stbd: ";
    rosidl_generator_traits::value_to_yaml(msg.thruster_pwm_stbd, out);
    out << "\n";
  }

  // member: azimuth_angle_port
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "azimuth_angle_port: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth_angle_port, out);
    out << "\n";
  }

  // member: azimuth_angle_stbd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "azimuth_angle_stbd: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth_angle_stbd, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ControlType & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace wamv_msgs

namespace rosidl_generator_traits
{

[[deprecated("use wamv_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const wamv_msgs::msg::ControlType & msg,
  std::ostream & out, size_t indentation = 0)
{
  wamv_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wamv_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const wamv_msgs::msg::ControlType & msg)
{
  return wamv_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<wamv_msgs::msg::ControlType>()
{
  return "wamv_msgs::msg::ControlType";
}

template<>
inline const char * name<wamv_msgs::msg::ControlType>()
{
  return "wamv_msgs/msg/ControlType";
}

template<>
struct has_fixed_size<wamv_msgs::msg::ControlType>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<wamv_msgs::msg::ControlType>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<wamv_msgs::msg::ControlType>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WAMV_MSGS__MSG__DETAIL__CONTROL_TYPE__TRAITS_HPP_
