// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from roverc:msg/RGB.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "roverc/msg/detail/rgb__rosidl_typesupport_introspection_c.h"
#include "roverc/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "roverc/msg/detail/rgb__functions.h"
#include "roverc/msg/detail/rgb__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void roverc__msg__RGB__rosidl_typesupport_introspection_c__RGB_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roverc__msg__RGB__init(message_memory);
}

void roverc__msg__RGB__rosidl_typesupport_introspection_c__RGB_fini_function(void * message_memory)
{
  roverc__msg__RGB__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember roverc__msg__RGB__rosidl_typesupport_introspection_c__RGB_message_member_array[3] = {
  {
    "red",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roverc__msg__RGB, red),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "green",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roverc__msg__RGB, green),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "blue",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roverc__msg__RGB, blue),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers roverc__msg__RGB__rosidl_typesupport_introspection_c__RGB_message_members = {
  "roverc__msg",  // message namespace
  "RGB",  // message name
  3,  // number of fields
  sizeof(roverc__msg__RGB),
  false,  // has_any_key_member_
  roverc__msg__RGB__rosidl_typesupport_introspection_c__RGB_message_member_array,  // message members
  roverc__msg__RGB__rosidl_typesupport_introspection_c__RGB_init_function,  // function to initialize message memory (memory has to be allocated)
  roverc__msg__RGB__rosidl_typesupport_introspection_c__RGB_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t roverc__msg__RGB__rosidl_typesupport_introspection_c__RGB_message_type_support_handle = {
  0,
  &roverc__msg__RGB__rosidl_typesupport_introspection_c__RGB_message_members,
  get_message_typesupport_handle_function,
  &roverc__msg__RGB__get_type_hash,
  &roverc__msg__RGB__get_type_description,
  &roverc__msg__RGB__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roverc
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roverc, msg, RGB)() {
  if (!roverc__msg__RGB__rosidl_typesupport_introspection_c__RGB_message_type_support_handle.typesupport_identifier) {
    roverc__msg__RGB__rosidl_typesupport_introspection_c__RGB_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &roverc__msg__RGB__rosidl_typesupport_introspection_c__RGB_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
