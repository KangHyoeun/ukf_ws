// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wamv_msgs:msg/RLType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__RL_TYPE__STRUCT_H_
#define WAMV_MSGS__MSG__DETAIL__RL_TYPE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'navigation'
#include "wamv_msgs/msg/detail/navigation_type__struct.h"

/// Struct defined in msg/RLType in the package wamv_msgs.
typedef struct wamv_msgs__msg__RLType
{
  std_msgs__msg__Header header;
  wamv_msgs__msg__NavigationType navigation;
  double left_thrust;
  double right_thrust;
} wamv_msgs__msg__RLType;

// Struct for a sequence of wamv_msgs__msg__RLType.
typedef struct wamv_msgs__msg__RLType__Sequence
{
  wamv_msgs__msg__RLType * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wamv_msgs__msg__RLType__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAMV_MSGS__MSG__DETAIL__RL_TYPE__STRUCT_H_
