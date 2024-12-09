// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from wamv_msgs:msg/NavigationType.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "wamv_msgs/msg/detail/navigation_type__rosidl_typesupport_introspection_c.h"
#include "wamv_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "wamv_msgs/msg/detail/navigation_type__functions.h"
#include "wamv_msgs/msg/detail/navigation_type__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void wamv_msgs__msg__NavigationType__rosidl_typesupport_introspection_c__NavigationType_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  wamv_msgs__msg__NavigationType__init(message_memory);
}

void wamv_msgs__msg__NavigationType__rosidl_typesupport_introspection_c__NavigationType_fini_function(void * message_memory)
{
  wamv_msgs__msg__NavigationType__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember wamv_msgs__msg__NavigationType__rosidl_typesupport_introspection_c__NavigationType_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wamv_msgs__msg__NavigationType, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wamv_msgs__msg__NavigationType, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wamv_msgs__msg__NavigationType, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "psi",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wamv_msgs__msg__NavigationType, psi),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "u",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wamv_msgs__msg__NavigationType, u),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "v",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wamv_msgs__msg__NavigationType, v),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "r",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wamv_msgs__msg__NavigationType, r),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "w",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wamv_msgs__msg__NavigationType, w),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers wamv_msgs__msg__NavigationType__rosidl_typesupport_introspection_c__NavigationType_message_members = {
  "wamv_msgs__msg",  // message namespace
  "NavigationType",  // message name
  8,  // number of fields
  sizeof(wamv_msgs__msg__NavigationType),
  wamv_msgs__msg__NavigationType__rosidl_typesupport_introspection_c__NavigationType_message_member_array,  // message members
  wamv_msgs__msg__NavigationType__rosidl_typesupport_introspection_c__NavigationType_init_function,  // function to initialize message memory (memory has to be allocated)
  wamv_msgs__msg__NavigationType__rosidl_typesupport_introspection_c__NavigationType_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t wamv_msgs__msg__NavigationType__rosidl_typesupport_introspection_c__NavigationType_message_type_support_handle = {
  0,
  &wamv_msgs__msg__NavigationType__rosidl_typesupport_introspection_c__NavigationType_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_wamv_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wamv_msgs, msg, NavigationType)() {
  wamv_msgs__msg__NavigationType__rosidl_typesupport_introspection_c__NavigationType_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!wamv_msgs__msg__NavigationType__rosidl_typesupport_introspection_c__NavigationType_message_type_support_handle.typesupport_identifier) {
    wamv_msgs__msg__NavigationType__rosidl_typesupport_introspection_c__NavigationType_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &wamv_msgs__msg__NavigationType__rosidl_typesupport_introspection_c__NavigationType_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
