// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from roverc:msg/WheelSpeed.idl
// generated code does not contain a copyright notice

#include "roverc/msg/detail/wheel_speed__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_roverc
const rosidl_type_hash_t *
roverc__msg__WheelSpeed__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8d, 0x45, 0xc5, 0xb1, 0xca, 0x4a, 0x26, 0x4a,
      0xa0, 0x3e, 0x4c, 0x71, 0x64, 0x2c, 0xdc, 0x3c,
      0x2d, 0x43, 0xd4, 0x0e, 0x6d, 0x3f, 0xd4, 0xb1,
      0xa3, 0xd6, 0x51, 0x85, 0xea, 0x0d, 0x2c, 0x9c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char roverc__msg__WheelSpeed__TYPE_NAME[] = "roverc/msg/WheelSpeed";

// Define type names, field names, and default values
static char roverc__msg__WheelSpeed__FIELD_NAME__front_right[] = "front_right";
static char roverc__msg__WheelSpeed__FIELD_NAME__front_left[] = "front_left";
static char roverc__msg__WheelSpeed__FIELD_NAME__rear_right[] = "rear_right";
static char roverc__msg__WheelSpeed__FIELD_NAME__rear_left[] = "rear_left";

static rosidl_runtime_c__type_description__Field roverc__msg__WheelSpeed__FIELDS[] = {
  {
    {roverc__msg__WheelSpeed__FIELD_NAME__front_right, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roverc__msg__WheelSpeed__FIELD_NAME__front_left, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roverc__msg__WheelSpeed__FIELD_NAME__rear_right, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roverc__msg__WheelSpeed__FIELD_NAME__rear_left, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
roverc__msg__WheelSpeed__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {roverc__msg__WheelSpeed__TYPE_NAME, 21, 21},
      {roverc__msg__WheelSpeed__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int8 front_right\n"
  "int8 front_left\n"
  "int8 rear_right\n"
  "int8 rear_left";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
roverc__msg__WheelSpeed__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {roverc__msg__WheelSpeed__TYPE_NAME, 21, 21},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 63, 63},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
roverc__msg__WheelSpeed__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *roverc__msg__WheelSpeed__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
