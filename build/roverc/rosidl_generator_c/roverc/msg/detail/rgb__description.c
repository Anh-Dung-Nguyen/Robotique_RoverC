// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from roverc:msg/RGB.idl
// generated code does not contain a copyright notice

#include "roverc/msg/detail/rgb__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_roverc
const rosidl_type_hash_t *
roverc__msg__RGB__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2b, 0xb2, 0x59, 0xbc, 0x6c, 0x97, 0x3b, 0x37,
      0xf9, 0x97, 0xaa, 0xec, 0xc5, 0x7e, 0xf0, 0x93,
      0xa8, 0x6f, 0x96, 0x48, 0x4d, 0xaf, 0xac, 0xab,
      0x5f, 0xc3, 0x29, 0x01, 0x81, 0x4e, 0xef, 0x1b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char roverc__msg__RGB__TYPE_NAME[] = "roverc/msg/RGB";

// Define type names, field names, and default values
static char roverc__msg__RGB__FIELD_NAME__red[] = "red";
static char roverc__msg__RGB__FIELD_NAME__green[] = "green";
static char roverc__msg__RGB__FIELD_NAME__blue[] = "blue";

static rosidl_runtime_c__type_description__Field roverc__msg__RGB__FIELDS[] = {
  {
    {roverc__msg__RGB__FIELD_NAME__red, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roverc__msg__RGB__FIELD_NAME__green, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roverc__msg__RGB__FIELD_NAME__blue, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
roverc__msg__RGB__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {roverc__msg__RGB__TYPE_NAME, 14, 14},
      {roverc__msg__RGB__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 red\n"
  "float32 green\n"
  "float32 blue";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
roverc__msg__RGB__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {roverc__msg__RGB__TYPE_NAME, 14, 14},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 39, 39},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
roverc__msg__RGB__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *roverc__msg__RGB__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
