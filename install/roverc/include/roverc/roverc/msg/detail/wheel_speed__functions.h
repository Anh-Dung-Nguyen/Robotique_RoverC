// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from roverc:msg/WheelSpeed.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roverc/msg/wheel_speed.h"


#ifndef ROVERC__MSG__DETAIL__WHEEL_SPEED__FUNCTIONS_H_
#define ROVERC__MSG__DETAIL__WHEEL_SPEED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "roverc/msg/rosidl_generator_c__visibility_control.h"

#include "roverc/msg/detail/wheel_speed__struct.h"

/// Initialize msg/WheelSpeed message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * roverc__msg__WheelSpeed
 * )) before or use
 * roverc__msg__WheelSpeed__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_roverc
bool
roverc__msg__WheelSpeed__init(roverc__msg__WheelSpeed * msg);

/// Finalize msg/WheelSpeed message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_roverc
void
roverc__msg__WheelSpeed__fini(roverc__msg__WheelSpeed * msg);

/// Create msg/WheelSpeed message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * roverc__msg__WheelSpeed__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_roverc
roverc__msg__WheelSpeed *
roverc__msg__WheelSpeed__create(void);

/// Destroy msg/WheelSpeed message.
/**
 * It calls
 * roverc__msg__WheelSpeed__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_roverc
void
roverc__msg__WheelSpeed__destroy(roverc__msg__WheelSpeed * msg);

/// Check for msg/WheelSpeed message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_roverc
bool
roverc__msg__WheelSpeed__are_equal(const roverc__msg__WheelSpeed * lhs, const roverc__msg__WheelSpeed * rhs);

/// Copy a msg/WheelSpeed message.
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
ROSIDL_GENERATOR_C_PUBLIC_roverc
bool
roverc__msg__WheelSpeed__copy(
  const roverc__msg__WheelSpeed * input,
  roverc__msg__WheelSpeed * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_roverc
const rosidl_type_hash_t *
roverc__msg__WheelSpeed__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_roverc
const rosidl_runtime_c__type_description__TypeDescription *
roverc__msg__WheelSpeed__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_roverc
const rosidl_runtime_c__type_description__TypeSource *
roverc__msg__WheelSpeed__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_roverc
const rosidl_runtime_c__type_description__TypeSource__Sequence *
roverc__msg__WheelSpeed__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/WheelSpeed messages.
/**
 * It allocates the memory for the number of elements and calls
 * roverc__msg__WheelSpeed__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_roverc
bool
roverc__msg__WheelSpeed__Sequence__init(roverc__msg__WheelSpeed__Sequence * array, size_t size);

/// Finalize array of msg/WheelSpeed messages.
/**
 * It calls
 * roverc__msg__WheelSpeed__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_roverc
void
roverc__msg__WheelSpeed__Sequence__fini(roverc__msg__WheelSpeed__Sequence * array);

/// Create array of msg/WheelSpeed messages.
/**
 * It allocates the memory for the array and calls
 * roverc__msg__WheelSpeed__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_roverc
roverc__msg__WheelSpeed__Sequence *
roverc__msg__WheelSpeed__Sequence__create(size_t size);

/// Destroy array of msg/WheelSpeed messages.
/**
 * It calls
 * roverc__msg__WheelSpeed__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_roverc
void
roverc__msg__WheelSpeed__Sequence__destroy(roverc__msg__WheelSpeed__Sequence * array);

/// Check for msg/WheelSpeed message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_roverc
bool
roverc__msg__WheelSpeed__Sequence__are_equal(const roverc__msg__WheelSpeed__Sequence * lhs, const roverc__msg__WheelSpeed__Sequence * rhs);

/// Copy an array of msg/WheelSpeed messages.
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
ROSIDL_GENERATOR_C_PUBLIC_roverc
bool
roverc__msg__WheelSpeed__Sequence__copy(
  const roverc__msg__WheelSpeed__Sequence * input,
  roverc__msg__WheelSpeed__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ROVERC__MSG__DETAIL__WHEEL_SPEED__FUNCTIONS_H_
