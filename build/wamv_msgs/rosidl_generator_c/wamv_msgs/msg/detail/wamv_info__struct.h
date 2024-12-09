// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wamv_msgs:msg/WAMVInfo.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__WAMV_INFO__STRUCT_H_
#define WAMV_MSGS__MSG__DETAIL__WAMV_INFO__STRUCT_H_

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
// Member 'ukf_navigation'
// Member 'navigation'
#include "wamv_msgs/msg/detail/navigation_type__struct.h"
// Member 'guidance'
#include "wamv_msgs/msg/detail/guidance_type__struct.h"
// Member 'control'
#include "wamv_msgs/msg/detail/control_type__struct.h"

/// Struct defined in msg/WAMVInfo in the package wamv_msgs.
typedef struct wamv_msgs__msg__WAMVInfo
{
  std_msgs__msg__Header header;
  wamv_msgs__msg__NavigationType ukf_navigation;
  wamv_msgs__msg__NavigationType navigation;
  wamv_msgs__msg__GuidanceType guidance;
  wamv_msgs__msg__ControlType control;
} wamv_msgs__msg__WAMVInfo;

// Struct for a sequence of wamv_msgs__msg__WAMVInfo.
typedef struct wamv_msgs__msg__WAMVInfo__Sequence
{
  wamv_msgs__msg__WAMVInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wamv_msgs__msg__WAMVInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAMV_MSGS__MSG__DETAIL__WAMV_INFO__STRUCT_H_
