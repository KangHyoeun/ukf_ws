// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from wamv_msgs:msg/WAMVInfo.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__WAMV_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define WAMV_MSGS__MSG__DETAIL__WAMV_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "wamv_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "wamv_msgs/msg/detail/wamv_info__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace wamv_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wamv_msgs
cdr_serialize(
  const wamv_msgs::msg::WAMVInfo & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wamv_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  wamv_msgs::msg::WAMVInfo & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wamv_msgs
get_serialized_size(
  const wamv_msgs::msg::WAMVInfo & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wamv_msgs
max_serialized_size_WAMVInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace wamv_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wamv_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wamv_msgs, msg, WAMVInfo)();

#ifdef __cplusplus
}
#endif

#endif  // WAMV_MSGS__MSG__DETAIL__WAMV_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
