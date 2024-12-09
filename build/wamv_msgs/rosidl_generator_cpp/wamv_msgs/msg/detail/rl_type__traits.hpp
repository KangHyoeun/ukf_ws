// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wamv_msgs:msg/RLType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__RL_TYPE__TRAITS_HPP_
#define WAMV_MSGS__MSG__DETAIL__RL_TYPE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wamv_msgs/msg/detail/rl_type__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'navigation'
#include "wamv_msgs/msg/detail/navigation_type__traits.hpp"

namespace wamv_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RLType & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: navigation
  {
    out << "navigation: ";
    to_flow_style_yaml(msg.navigation, out);
    out << ", ";
  }

  // member: left_thrust
  {
    out << "left_thrust: ";
    rosidl_generator_traits::value_to_yaml(msg.left_thrust, out);
    out << ", ";
  }

  // member: right_thrust
  {
    out << "right_thrust: ";
    rosidl_generator_traits::value_to_yaml(msg.right_thrust, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RLType & msg,
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

  // member: navigation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "navigation:\n";
    to_block_style_yaml(msg.navigation, out, indentation + 2);
  }

  // member: left_thrust
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_thrust: ";
    rosidl_generator_traits::value_to_yaml(msg.left_thrust, out);
    out << "\n";
  }

  // member: right_thrust
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_thrust: ";
    rosidl_generator_traits::value_to_yaml(msg.right_thrust, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RLType & msg, bool use_flow_style = false)
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
  const wamv_msgs::msg::RLType & msg,
  std::ostream & out, size_t indentation = 0)
{
  wamv_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wamv_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const wamv_msgs::msg::RLType & msg)
{
  return wamv_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<wamv_msgs::msg::RLType>()
{
  return "wamv_msgs::msg::RLType";
}

template<>
inline const char * name<wamv_msgs::msg::RLType>()
{
  return "wamv_msgs/msg/RLType";
}

template<>
struct has_fixed_size<wamv_msgs::msg::RLType>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value && has_fixed_size<wamv_msgs::msg::NavigationType>::value> {};

template<>
struct has_bounded_size<wamv_msgs::msg::RLType>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value && has_bounded_size<wamv_msgs::msg::NavigationType>::value> {};

template<>
struct is_message<wamv_msgs::msg::RLType>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WAMV_MSGS__MSG__DETAIL__RL_TYPE__TRAITS_HPP_
