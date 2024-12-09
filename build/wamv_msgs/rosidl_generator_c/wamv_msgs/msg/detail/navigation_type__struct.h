// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wamv_msgs:msg/NavigationType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__NAVIGATION_TYPE__STRUCT_H_
#define WAMV_MSGS__MSG__DETAIL__NAVIGATION_TYPE__STRUCT_H_

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

/// Struct defined in msg/NavigationType in the package wamv_msgs.
typedef struct wamv_msgs__msg__NavigationType
{
  std_msgs__msg__Header header;
  double x;
  double y;
  double psi;
  double u;
  double v;
  double r;
  double w;
} wamv_msgs__msg__NavigationType;

// Struct for a sequence of wamv_msgs__msg__NavigationType.
typedef struct wamv_msgs__msg__NavigationType__Sequence
{
  wamv_msgs__msg__NavigationType * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wamv_msgs__msg__NavigationType__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAMV_MSGS__MSG__DETAIL__NAVIGATION_TYPE__STRUCT_H_
