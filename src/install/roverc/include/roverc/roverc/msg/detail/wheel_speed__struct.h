// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roverc:msg/WheelSpeed.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roverc/msg/wheel_speed.h"


#ifndef ROVERC__MSG__DETAIL__WHEEL_SPEED__STRUCT_H_
#define ROVERC__MSG__DETAIL__WHEEL_SPEED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/WheelSpeed in the package roverc.
typedef struct roverc__msg__WheelSpeed
{
  int8_t front_right;
  int8_t front_left;
  int8_t rear_right;
  int8_t rear_left;
} roverc__msg__WheelSpeed;

// Struct for a sequence of roverc__msg__WheelSpeed.
typedef struct roverc__msg__WheelSpeed__Sequence
{
  roverc__msg__WheelSpeed * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roverc__msg__WheelSpeed__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROVERC__MSG__DETAIL__WHEEL_SPEED__STRUCT_H_
