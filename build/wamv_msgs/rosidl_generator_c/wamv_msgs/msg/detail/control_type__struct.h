// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wamv_msgs:msg/ControlType.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__CONTROL_TYPE__STRUCT_H_
#define WAMV_MSGS__MSG__DETAIL__CONTROL_TYPE__STRUCT_H_

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

/// Struct defined in msg/ControlType in the package wamv_msgs.
typedef struct wamv_msgs__msg__ControlType
{
  std_msgs__msg__Header header;
  double delta_x;
  double delta_y;
  double delta_psi;
  double pwm_standard;
  double thruster_pwm_port;
  double thruster_pwm_stbd;
  double azimuth_angle_port;
  double azimuth_angle_stbd;
} wamv_msgs__msg__ControlType;

// Struct for a sequence of wamv_msgs__msg__ControlType.
typedef struct wamv_msgs__msg__ControlType__Sequence
{
  wamv_msgs__msg__ControlType * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wamv_msgs__msg__ControlType__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAMV_MSGS__MSG__DETAIL__CONTROL_TYPE__STRUCT_H_
