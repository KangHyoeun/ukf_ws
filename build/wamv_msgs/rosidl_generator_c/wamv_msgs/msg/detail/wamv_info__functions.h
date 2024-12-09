// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from wamv_msgs:msg/WAMVInfo.idl
// generated code does not contain a copyright notice

#ifndef WAMV_MSGS__MSG__DETAIL__WAMV_INFO__FUNCTIONS_H_
#define WAMV_MSGS__MSG__DETAIL__WAMV_INFO__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "wamv_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "wamv_msgs/msg/detail/wamv_info__struct.h"

/// Initialize msg/WAMVInfo message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * wamv_msgs__msg__WAMVInfo
 * )) before or use
 * wamv_msgs__msg__WAMVInfo__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_wamv_msgs
bool
wamv_msgs__msg__WAMVInfo__init(wamv_msgs__msg__WAMVInfo * msg);

/// Finalize msg/WAMVInfo message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_wamv_msgs
void
wamv_msgs__msg__WAMVInfo__fini(wamv_msgs__msg__WAMVInfo * msg);

/// Create msg/WAMVInfo message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * wamv_msgs__msg__WAMVInfo__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_wamv_msgs
wamv_msgs__msg__WAMVInfo *
wamv_msgs__msg__WAMVInfo__create();

/// Destroy msg/WAMVInfo message.
/**
 * It calls
 * wamv_msgs__msg__WAMVInfo__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_wamv_msgs
void
wamv_msgs__msg__WAMVInfo__destroy(wamv_msgs__msg__WAMVInfo * msg);

/// Check for msg/WAMVInfo message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_wamv_msgs
bool
wamv_msgs__msg__WAMVInfo__are_equal(const wamv_msgs__msg__WAMVInfo * lhs, const wamv_msgs__msg__WAMVInfo * rhs);

/// Copy a msg/WAMVInfo message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_wamv_msgs
bool
wamv_msgs__msg__WAMVInfo__copy(
  const wamv_msgs__msg__WAMVInfo * input,
  wamv_msgs__msg__WAMVInfo * output);

/// Initialize array of msg/WAMVInfo messages.
/**
 * It allocates the memory for the number of elements and calls
 * wamv_msgs__msg__WAMVInfo__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_wamv_msgs
bool
wamv_msgs__msg__WAMVInfo__Sequence__init(wamv_msgs__msg__WAMVInfo__Sequence * array, size_t size);

/// Finalize array of msg/WAMVInfo messages.
/**
 * It calls
 * wamv_msgs__msg__WAMVInfo__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_wamv_msgs
void
wamv_msgs__msg__WAMVInfo__Sequence__fini(wamv_msgs__msg__WAMVInfo__Sequence * array);

/// Create array of msg/WAMVInfo messages.
/**
 * It allocates the memory for the array and calls
 * wamv_msgs__msg__WAMVInfo__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_wamv_msgs
wamv_msgs__msg__WAMVInfo__Sequence *
wamv_msgs__msg__WAMVInfo__Sequence__create(size_t size);

/// Destroy array of msg/WAMVInfo messages.
/**
 * It calls
 * wamv_msgs__msg__WAMVInfo__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_wamv_msgs
void
wamv_msgs__msg__WAMVInfo__Sequence__destroy(wamv_msgs__msg__WAMVInfo__Sequence * array);

/// Check for msg/WAMVInfo message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_wamv_msgs
bool
wamv_msgs__msg__WAMVInfo__Sequence__are_equal(const wamv_msgs__msg__WAMVInfo__Sequence * lhs, const wamv_msgs__msg__WAMVInfo__Sequence * rhs);

/// Copy an array of msg/WAMVInfo messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_wamv_msgs
bool
wamv_msgs__msg__WAMVInfo__Sequence__copy(
  const wamv_msgs__msg__WAMVInfo__Sequence * input,
  wamv_msgs__msg__WAMVInfo__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // WAMV_MSGS__MSG__DETAIL__WAMV_INFO__FUNCTIONS_H_
