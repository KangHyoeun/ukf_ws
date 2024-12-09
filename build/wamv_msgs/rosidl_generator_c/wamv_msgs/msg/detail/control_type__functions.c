// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from wamv_msgs:msg/ControlType.idl
// generated code does not contain a copyright notice
#include "wamv_msgs/msg/detail/control_type__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
wamv_msgs__msg__ControlType__init(wamv_msgs__msg__ControlType * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    wamv_msgs__msg__ControlType__fini(msg);
    return false;
  }
  // delta_x
  // delta_y
  // delta_psi
  // pwm_standard
  // thruster_pwm_port
  // thruster_pwm_stbd
  // azimuth_angle_port
  // azimuth_angle_stbd
  return true;
}

void
wamv_msgs__msg__ControlType__fini(wamv_msgs__msg__ControlType * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // delta_x
  // delta_y
  // delta_psi
  // pwm_standard
  // thruster_pwm_port
  // thruster_pwm_stbd
  // azimuth_angle_port
  // azimuth_angle_stbd
}

bool
wamv_msgs__msg__ControlType__are_equal(const wamv_msgs__msg__ControlType * lhs, const wamv_msgs__msg__ControlType * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // delta_x
  if (lhs->delta_x != rhs->delta_x) {
    return false;
  }
  // delta_y
  if (lhs->delta_y != rhs->delta_y) {
    return false;
  }
  // delta_psi
  if (lhs->delta_psi != rhs->delta_psi) {
    return false;
  }
  // pwm_standard
  if (lhs->pwm_standard != rhs->pwm_standard) {
    return false;
  }
  // thruster_pwm_port
  if (lhs->thruster_pwm_port != rhs->thruster_pwm_port) {
    return false;
  }
  // thruster_pwm_stbd
  if (lhs->thruster_pwm_stbd != rhs->thruster_pwm_stbd) {
    return false;
  }
  // azimuth_angle_port
  if (lhs->azimuth_angle_port != rhs->azimuth_angle_port) {
    return false;
  }
  // azimuth_angle_stbd
  if (lhs->azimuth_angle_stbd != rhs->azimuth_angle_stbd) {
    return false;
  }
  return true;
}

bool
wamv_msgs__msg__ControlType__copy(
  const wamv_msgs__msg__ControlType * input,
  wamv_msgs__msg__ControlType * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // delta_x
  output->delta_x = input->delta_x;
  // delta_y
  output->delta_y = input->delta_y;
  // delta_psi
  output->delta_psi = input->delta_psi;
  // pwm_standard
  output->pwm_standard = input->pwm_standard;
  // thruster_pwm_port
  output->thruster_pwm_port = input->thruster_pwm_port;
  // thruster_pwm_stbd
  output->thruster_pwm_stbd = input->thruster_pwm_stbd;
  // azimuth_angle_port
  output->azimuth_angle_port = input->azimuth_angle_port;
  // azimuth_angle_stbd
  output->azimuth_angle_stbd = input->azimuth_angle_stbd;
  return true;
}

wamv_msgs__msg__ControlType *
wamv_msgs__msg__ControlType__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wamv_msgs__msg__ControlType * msg = (wamv_msgs__msg__ControlType *)allocator.allocate(sizeof(wamv_msgs__msg__ControlType), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(wamv_msgs__msg__ControlType));
  bool success = wamv_msgs__msg__ControlType__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
wamv_msgs__msg__ControlType__destroy(wamv_msgs__msg__ControlType * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    wamv_msgs__msg__ControlType__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
wamv_msgs__msg__ControlType__Sequence__init(wamv_msgs__msg__ControlType__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wamv_msgs__msg__ControlType * data = NULL;

  if (size) {
    data = (wamv_msgs__msg__ControlType *)allocator.zero_allocate(size, sizeof(wamv_msgs__msg__ControlType), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = wamv_msgs__msg__ControlType__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        wamv_msgs__msg__ControlType__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
wamv_msgs__msg__ControlType__Sequence__fini(wamv_msgs__msg__ControlType__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      wamv_msgs__msg__ControlType__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

wamv_msgs__msg__ControlType__Sequence *
wamv_msgs__msg__ControlType__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wamv_msgs__msg__ControlType__Sequence * array = (wamv_msgs__msg__ControlType__Sequence *)allocator.allocate(sizeof(wamv_msgs__msg__ControlType__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = wamv_msgs__msg__ControlType__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
wamv_msgs__msg__ControlType__Sequence__destroy(wamv_msgs__msg__ControlType__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    wamv_msgs__msg__ControlType__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
wamv_msgs__msg__ControlType__Sequence__are_equal(const wamv_msgs__msg__ControlType__Sequence * lhs, const wamv_msgs__msg__ControlType__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!wamv_msgs__msg__ControlType__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
wamv_msgs__msg__ControlType__Sequence__copy(
  const wamv_msgs__msg__ControlType__Sequence * input,
  wamv_msgs__msg__ControlType__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(wamv_msgs__msg__ControlType);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    wamv_msgs__msg__ControlType * data =
      (wamv_msgs__msg__ControlType *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!wamv_msgs__msg__ControlType__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          wamv_msgs__msg__ControlType__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!wamv_msgs__msg__ControlType__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
