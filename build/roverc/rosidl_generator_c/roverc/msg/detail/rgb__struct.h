// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roverc:msg/RGB.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roverc/msg/rgb.h"


#ifndef ROVERC__MSG__DETAIL__RGB__STRUCT_H_
#define ROVERC__MSG__DETAIL__RGB__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/RGB in the package roverc.
typedef struct roverc__msg__RGB
{
  float red;
  float green;
  float blue;
} roverc__msg__RGB;

// Struct for a sequence of roverc__msg__RGB.
typedef struct roverc__msg__RGB__Sequence
{
  roverc__msg__RGB * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roverc__msg__RGB__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROVERC__MSG__DETAIL__RGB__STRUCT_H_
