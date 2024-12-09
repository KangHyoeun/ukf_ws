// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from wamv_msgs:msg/WAMVInfo.idl
// generated code does not contain a copyright notice
#include "wamv_msgs/msg/detail/wamv_info__rosidl_typesupport_fastrtps_cpp.hpp"
#include "wamv_msgs/msg/detail/wamv_info__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace wamv_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const wamv_msgs::msg::NavigationType &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  wamv_msgs::msg::NavigationType &);
size_t get_serialized_size(
  const wamv_msgs::msg::NavigationType &,
  size_t current_alignment);
size_t
max_serialized_size_NavigationType(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace wamv_msgs

// functions for wamv_msgs::msg::NavigationType already declared above

namespace wamv_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const wamv_msgs::msg::GuidanceType &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  wamv_msgs::msg::GuidanceType &);
size_t get_serialized_size(
  const wamv_msgs::msg::GuidanceType &,
  size_t current_alignment);
size_t
max_serialized_size_GuidanceType(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace wamv_msgs

namespace wamv_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const wamv_msgs::msg::ControlType &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  wamv_msgs::msg::ControlType &);
size_t get_serialized_size(
  const wamv_msgs::msg::ControlType &,
  size_t current_alignment);
size_t
max_serialized_size_ControlType(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace wamv_msgs


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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: ukf_navigation
  wamv_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.ukf_navigation,
    cdr);
  // Member: navigation
  wamv_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.navigation,
    cdr);
  // Member: guidance
  wamv_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.guidance,
    cdr);
  // Member: control
  wamv_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.control,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wamv_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  wamv_msgs::msg::WAMVInfo & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: ukf_navigation
  wamv_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.ukf_navigation);

  // Member: navigation
  wamv_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.navigation);

  // Member: guidance
  wamv_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.guidance);

  // Member: control
  wamv_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.control);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wamv_msgs
get_serialized_size(
  const wamv_msgs::msg::WAMVInfo & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: ukf_navigation

  current_alignment +=
    wamv_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.ukf_navigation, current_alignment);
  // Member: navigation

  current_alignment +=
    wamv_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.navigation, current_alignment);
  // Member: guidance

  current_alignment +=
    wamv_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.guidance, current_alignment);
  // Member: control

  current_alignment +=
    wamv_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.control, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wamv_msgs
max_serialized_size_WAMVInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: ukf_navigation
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        wamv_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_NavigationType(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: navigation
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        wamv_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_NavigationType(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: guidance
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        wamv_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_GuidanceType(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: control
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        wamv_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ControlType(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = wamv_msgs::msg::WAMVInfo;
    is_plain =
      (
      offsetof(DataType, control) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _WAMVInfo__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const wamv_msgs::msg::WAMVInfo *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _WAMVInfo__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<wamv_msgs::msg::WAMVInfo *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _WAMVInfo__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const wamv_msgs::msg::WAMVInfo *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _WAMVInfo__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_WAMVInfo(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _WAMVInfo__callbacks = {
  "wamv_msgs::msg",
  "WAMVInfo",
  _WAMVInfo__cdr_serialize,
  _WAMVInfo__cdr_deserialize,
  _WAMVInfo__get_serialized_size,
  _WAMVInfo__max_serialized_size
};

static rosidl_message_type_support_t _WAMVInfo__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_WAMVInfo__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace wamv_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_wamv_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<wamv_msgs::msg::WAMVInfo>()
{
  return &wamv_msgs::msg::typesupport_fastrtps_cpp::_WAMVInfo__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wamv_msgs, msg, WAMVInfo)() {
  return &wamv_msgs::msg::typesupport_fastrtps_cpp::_WAMVInfo__handle;
}

#ifdef __cplusplus
}
#endif
