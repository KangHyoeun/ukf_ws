// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wamv_msgs:msg/NavigationType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__NAVIGATION_TYPE__TRAITS_HPP_
#define WAMV_MSGS__MSG__DETAIL__NAVIGATION_TYPE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wamv_msgs/msg/detail/navigation_type__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace wamv_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavigationType & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: psi
  {
    out << "psi: ";
    rosidl_generator_traits::value_to_yaml(msg.psi, out);
    out << ", ";
  }

  // member: u
  {
    out << "u: ";
    rosidl_generator_traits::value_to_yaml(msg.u, out);
    out << ", ";
  }

  // member: v
  {
    out << "v: ";
    rosidl_generator_traits::value_to_yaml(msg.v, out);
    out << ", ";
  }

  // member: r
  {
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << ", ";
  }

  // member: w
  {
    out << "w: ";
    rosidl_generator_traits::value_to_yaml(msg.w, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigationType & msg,
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

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: psi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "psi: ";
    rosidl_generator_traits::value_to_yaml(msg.psi, out);
    out << "\n";
  }

  // member: u
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "u: ";
    rosidl_generator_traits::value_to_yaml(msg.u, out);
    out << "\n";
  }

  // member: v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v: ";
    rosidl_generator_traits::value_to_yaml(msg.v, out);
    out << "\n";
  }

  // member: r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << "\n";
  }

  // member: w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w: ";
    rosidl_generator_traits::value_to_yaml(msg.w, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigationType & msg, bool use_flow_style = false)
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
  const wamv_msgs::msg::NavigationType & msg,
  std::ostream & out, size_t indentation = 0)
{
  wamv_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wamv_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const wamv_msgs::msg::NavigationType & msg)
{
  return wamv_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<wamv_msgs::msg::NavigationType>()
{
  return "wamv_msgs::msg::NavigationType";
}

template<>
inline const char * name<wamv_msgs::msg::NavigationType>()
{
  return "wamv_msgs/msg/NavigationType";
}

template<>
struct has_fixed_size<wamv_msgs::msg::NavigationType>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<wamv_msgs::msg::NavigationType>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<wamv_msgs::msg::NavigationType>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WAMV_MSGS__MSG__DETAIL__NAVIGATION_TYPE__TRAITS_HPP_
