// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wamv_msgs:msg/WAMVInfo.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__WAMV_INFO__TRAITS_HPP_
#define WAMV_MSGS__MSG__DETAIL__WAMV_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wamv_msgs/msg/detail/wamv_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'ukf_navigation'
// Member 'navigation'
#include "wamv_msgs/msg/detail/navigation_type__traits.hpp"
// Member 'guidance'
#include "wamv_msgs/msg/detail/guidance_type__traits.hpp"
// Member 'control'
#include "wamv_msgs/msg/detail/control_type__traits.hpp"

namespace wamv_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const WAMVInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: ukf_navigation
  {
    out << "ukf_navigation: ";
    to_flow_style_yaml(msg.ukf_navigation, out);
    out << ", ";
  }

  // member: navigation
  {
    out << "navigation: ";
    to_flow_style_yaml(msg.navigation, out);
    out << ", ";
  }

  // member: guidance
  {
    out << "guidance: ";
    to_flow_style_yaml(msg.guidance, out);
    out << ", ";
  }

  // member: control
  {
    out << "control: ";
    to_flow_style_yaml(msg.control, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WAMVInfo & msg,
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

  // member: ukf_navigation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ukf_navigation:\n";
    to_block_style_yaml(msg.ukf_navigation, out, indentation + 2);
  }

  // member: navigation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "navigation:\n";
    to_block_style_yaml(msg.navigation, out, indentation + 2);
  }

  // member: guidance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "guidance:\n";
    to_block_style_yaml(msg.guidance, out, indentation + 2);
  }

  // member: control
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control:\n";
    to_block_style_yaml(msg.control, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WAMVInfo & msg, bool use_flow_style = false)
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
  const wamv_msgs::msg::WAMVInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  wamv_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wamv_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const wamv_msgs::msg::WAMVInfo & msg)
{
  return wamv_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<wamv_msgs::msg::WAMVInfo>()
{
  return "wamv_msgs::msg::WAMVInfo";
}

template<>
inline const char * name<wamv_msgs::msg::WAMVInfo>()
{
  return "wamv_msgs/msg/WAMVInfo";
}

template<>
struct has_fixed_size<wamv_msgs::msg::WAMVInfo>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value && has_fixed_size<wamv_msgs::msg::ControlType>::value && has_fixed_size<wamv_msgs::msg::GuidanceType>::value && has_fixed_size<wamv_msgs::msg::NavigationType>::value> {};

template<>
struct has_bounded_size<wamv_msgs::msg::WAMVInfo>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value && has_bounded_size<wamv_msgs::msg::ControlType>::value && has_bounded_size<wamv_msgs::msg::GuidanceType>::value && has_bounded_size<wamv_msgs::msg::NavigationType>::value> {};

template<>
struct is_message<wamv_msgs::msg::WAMVInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WAMV_MSGS__MSG__DETAIL__WAMV_INFO__TRAITS_HPP_
