// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from wamv_msgs:msg/ControlType.idl
// generated code does not contain a copyright notice
#include "wamv_msgs/msg/detail/control_type__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "wamv_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "wamv_msgs/msg/detail/control_type__struct.h"
#include "wamv_msgs/msg/detail/control_type__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wamv_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wamv_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wamv_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _ControlType__ros_msg_type = wamv_msgs__msg__ControlType;

static bool _ControlType__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ControlType__ros_msg_type * ros_message = static_cast<const _ControlType__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: delta_x
  {
    cdr << ros_message->delta_x;
  }

  // Field name: delta_y
  {
    cdr << ros_message->delta_y;
  }

  // Field name: delta_psi
  {
    cdr << ros_message->delta_psi;
  }

  // Field name: pwm_standard
  {
    cdr << ros_message->pwm_standard;
  }

  // Field name: thruster_pwm_port
  {
    cdr << ros_message->thruster_pwm_port;
  }

  // Field name: thruster_pwm_stbd
  {
    cdr << ros_message->thruster_pwm_stbd;
  }

  // Field name: azimuth_angle_port
  {
    cdr << ros_message->azimuth_angle_port;
  }

  // Field name: azimuth_angle_stbd
  {
    cdr << ros_message->azimuth_angle_stbd;
  }

  return true;
}

static bool _ControlType__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ControlType__ros_msg_type * ros_message = static_cast<_ControlType__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: delta_x
  {
    cdr >> ros_message->delta_x;
  }

  // Field name: delta_y
  {
    cdr >> ros_message->delta_y;
  }

  // Field name: delta_psi
  {
    cdr >> ros_message->delta_psi;
  }

  // Field name: pwm_standard
  {
    cdr >> ros_message->pwm_standard;
  }

  // Field name: thruster_pwm_port
  {
    cdr >> ros_message->thruster_pwm_port;
  }

  // Field name: thruster_pwm_stbd
  {
    cdr >> ros_message->thruster_pwm_stbd;
  }

  // Field name: azimuth_angle_port
  {
    cdr >> ros_message->azimuth_angle_port;
  }

  // Field name: azimuth_angle_stbd
  {
    cdr >> ros_message->azimuth_angle_stbd;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wamv_msgs
size_t get_serialized_size_wamv_msgs__msg__ControlType(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ControlType__ros_msg_type * ros_message = static_cast<const _ControlType__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name delta_x
  {
    size_t item_size = sizeof(ros_message->delta_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name delta_y
  {
    size_t item_size = sizeof(ros_message->delta_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name delta_psi
  {
    size_t item_size = sizeof(ros_message->delta_psi);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pwm_standard
  {
    size_t item_size = sizeof(ros_message->pwm_standard);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name thruster_pwm_port
  {
    size_t item_size = sizeof(ros_message->thruster_pwm_port);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name thruster_pwm_stbd
  {
    size_t item_size = sizeof(ros_message->thruster_pwm_stbd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name azimuth_angle_port
  {
    size_t item_size = sizeof(ros_message->azimuth_angle_port);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name azimuth_angle_stbd
  {
    size_t item_size = sizeof(ros_message->azimuth_angle_stbd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ControlType__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_wamv_msgs__msg__ControlType(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wamv_msgs
size_t max_serialized_size_wamv_msgs__msg__ControlType(
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

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: delta_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: delta_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: delta_psi
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: pwm_standard
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: thruster_pwm_port
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: thruster_pwm_stbd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: azimuth_angle_port
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: azimuth_angle_stbd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = wamv_msgs__msg__ControlType;
    is_plain =
      (
      offsetof(DataType, azimuth_angle_stbd) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ControlType__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_wamv_msgs__msg__ControlType(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ControlType = {
  "wamv_msgs::msg",
  "ControlType",
  _ControlType__cdr_serialize,
  _ControlType__cdr_deserialize,
  _ControlType__get_serialized_size,
  _ControlType__max_serialized_size
};

static rosidl_message_type_support_t _ControlType__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ControlType,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, wamv_msgs, msg, ControlType)() {
  return &_ControlType__type_support;
}

#if defined(__cplusplus)
}
#endif
