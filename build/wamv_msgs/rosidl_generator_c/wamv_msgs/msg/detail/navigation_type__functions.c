// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from wamv_msgs:msg/NavigationType.idl
// generated code does not contain a copyright notice
#include "wamv_msgs/msg/detail/navigation_type__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
wamv_msgs__msg__NavigationType__init(wamv_msgs__msg__NavigationType * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    wamv_msgs__msg__NavigationType__fini(msg);
    return false;
  }
  // x
  // y
  // psi
  // u
  // v
  // r
  // w
  return true;
}

void
wamv_msgs__msg__NavigationType__fini(wamv_msgs__msg__NavigationType * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // x
  // y
  // psi
  // u
  // v
  // r
  // w
}

bool
wamv_msgs__msg__NavigationType__are_equal(const wamv_msgs__msg__NavigationType * lhs, const wamv_msgs__msg__NavigationType * rhs)
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
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // psi
  if (lhs->psi != rhs->psi) {
    return false;
  }
  // u
  if (lhs->u != rhs->u) {
    return false;
  }
  // v
  if (lhs->v != rhs->v) {
    return false;
  }
  // r
  if (lhs->r != rhs->r) {
    return false;
  }
  // w
  if (lhs->w != rhs->w) {
    return false;
  }
  return true;
}

bool
wamv_msgs__msg__NavigationType__copy(
  const wamv_msgs__msg__NavigationType * input,
  wamv_msgs__msg__NavigationType * output)
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
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // psi
  output->psi = input->psi;
  // u
  output->u = input->u;
  // v
  output->v = input->v;
  // r
  output->r = input->r;
  // w
  output->w = input->w;
  return true;
}

wamv_msgs__msg__NavigationType *
wamv_msgs__msg__NavigationType__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wamv_msgs__msg__NavigationType * msg = (wamv_msgs__msg__NavigationType *)allocator.allocate(sizeof(wamv_msgs__msg__NavigationType), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(wamv_msgs__msg__NavigationType));
  bool success = wamv_msgs__msg__NavigationType__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
wamv_msgs__msg__NavigationType__destroy(wamv_msgs__msg__NavigationType * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    wamv_msgs__msg__NavigationType__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
wamv_msgs__msg__NavigationType__Sequence__init(wamv_msgs__msg__NavigationType__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wamv_msgs__msg__NavigationType * data = NULL;

  if (size) {
    data = (wamv_msgs__msg__NavigationType *)allocator.zero_allocate(size, sizeof(wamv_msgs__msg__NavigationType), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = wamv_msgs__msg__NavigationType__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        wamv_msgs__msg__NavigationType__fini(&data[i - 1]);
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
wamv_msgs__msg__NavigationType__Sequence__fini(wamv_msgs__msg__NavigationType__Sequence * array)
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
      wamv_msgs__msg__NavigationType__fini(&array->data[i]);
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

wamv_msgs__msg__NavigationType__Sequence *
wamv_msgs__msg__NavigationType__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wamv_msgs__msg__NavigationType__Sequence * array = (wamv_msgs__msg__NavigationType__Sequence *)allocator.allocate(sizeof(wamv_msgs__msg__NavigationType__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = wamv_msgs__msg__NavigationType__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
wamv_msgs__msg__NavigationType__Sequence__destroy(wamv_msgs__msg__NavigationType__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    wamv_msgs__msg__NavigationType__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
wamv_msgs__msg__NavigationType__Sequence__are_equal(const wamv_msgs__msg__NavigationType__Sequence * lhs, const wamv_msgs__msg__NavigationType__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!wamv_msgs__msg__NavigationType__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
wamv_msgs__msg__NavigationType__Sequence__copy(
  const wamv_msgs__msg__NavigationType__Sequence * input,
  wamv_msgs__msg__NavigationType__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(wamv_msgs__msg__NavigationType);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    wamv_msgs__msg__NavigationType * data =
      (wamv_msgs__msg__NavigationType *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!wamv_msgs__msg__NavigationType__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          wamv_msgs__msg__NavigationType__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!wamv_msgs__msg__NavigationType__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
