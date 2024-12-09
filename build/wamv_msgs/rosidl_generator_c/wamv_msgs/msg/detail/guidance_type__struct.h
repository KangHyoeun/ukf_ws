// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wamv_msgs:msg/GuidanceType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__GUIDANCE_TYPE__STRUCT_H_
#define WAMV_MSGS__MSG__DETAIL__GUIDANCE_TYPE__STRUCT_H_

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

/// Struct defined in msg/GuidanceType in the package wamv_msgs.
typedef struct wamv_msgs__msg__GuidanceType
{
  std_msgs__msg__Header header;
  double desired_psi;
  double error_x;
  double error_y;
  double error_psi;
  double distance;
  double x_waypoint;
  double y_waypoint;
} wamv_msgs__msg__GuidanceType;

// Struct for a sequence of wamv_msgs__msg__GuidanceType.
typedef struct wamv_msgs__msg__GuidanceType__Sequence
{
  wamv_msgs__msg__GuidanceType * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wamv_msgs__msg__GuidanceType__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAMV_MSGS__MSG__DETAIL__GUIDANCE_TYPE__STRUCT_H_
