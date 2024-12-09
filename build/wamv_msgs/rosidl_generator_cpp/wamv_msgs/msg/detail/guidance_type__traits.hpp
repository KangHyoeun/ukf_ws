// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wamv_msgs:msg/GuidanceType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__GUIDANCE_TYPE__TRAITS_HPP_
#define WAMV_MSGS__MSG__DETAIL__GUIDANCE_TYPE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wamv_msgs/msg/detail/guidance_type__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace wamv_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GuidanceType & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: desired_psi
  {
    out << "desired_psi: ";
    rosidl_generator_traits::value_to_yaml(msg.desired_psi, out);
    out << ", ";
  }

  // member: error_x
  {
    out << "error_x: ";
    rosidl_generator_traits::value_to_yaml(msg.error_x, out);
    out << ", ";
  }

  // member: error_y
  {
    out << "error_y: ";
    rosidl_generator_traits::value_to_yaml(msg.error_y, out);
    out << ", ";
  }

  // member: error_psi
  {
    out << "error_psi: ";
    rosidl_generator_traits::value_to_yaml(msg.error_psi, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << ", ";
  }

  // member: x_waypoint
  {
    out << "x_waypoint: ";
    rosidl_generator_traits::value_to_yaml(msg.x_waypoint, out);
    out << ", ";
  }

  // member: y_waypoint
  {
    out << "y_waypoint: ";
    rosidl_generator_traits::value_to_yaml(msg.y_waypoint, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GuidanceType & msg,
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

  // member: desired_psi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "desired_psi: ";
    rosidl_generator_traits::value_to_yaml(msg.desired_psi, out);
    out << "\n";
  }

  // member: error_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_x: ";
    rosidl_generator_traits::value_to_yaml(msg.error_x, out);
    out << "\n";
  }

  // member: error_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_y: ";
    rosidl_generator_traits::value_to_yaml(msg.error_y, out);
    out << "\n";
  }

  // member: error_psi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_psi: ";
    rosidl_generator_traits::value_to_yaml(msg.error_psi, out);
    out << "\n";
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }

  // member: x_waypoint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_waypoint: ";
    rosidl_generator_traits::value_to_yaml(msg.x_waypoint, out);
    out << "\n";
  }

  // member: y_waypoint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_waypoint: ";
    rosidl_generator_traits::value_to_yaml(msg.y_waypoint, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GuidanceType & msg, bool use_flow_style = false)
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
  const wamv_msgs::msg::GuidanceType & msg,
  std::ostream & out, size_t indentation = 0)
{
  wamv_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wamv_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const wamv_msgs::msg::GuidanceType & msg)
{
  return wamv_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<wamv_msgs::msg::GuidanceType>()
{
  return "wamv_msgs::msg::GuidanceType";
}

template<>
inline const char * name<wamv_msgs::msg::GuidanceType>()
{
  return "wamv_msgs/msg/GuidanceType";
}

template<>
struct has_fixed_size<wamv_msgs::msg::GuidanceType>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<wamv_msgs::msg::GuidanceType>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<wamv_msgs::msg::GuidanceType>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WAMV_MSGS__MSG__DETAIL__GUIDANCE_TYPE__TRAITS_HPP_
