// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from roverc:msg/RGB.idl
// generated code does not contain a copyright notice
#ifndef ROVERC__MSG__DETAIL__RGB__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ROVERC__MSG__DETAIL__RGB__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "roverc/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "roverc/msg/detail/rgb__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roverc
bool cdr_serialize_roverc__msg__RGB(
  const roverc__msg__RGB * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roverc
bool cdr_deserialize_roverc__msg__RGB(
  eprosima::fastcdr::Cdr &,
  roverc__msg__RGB * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roverc
size_t get_serialized_size_roverc__msg__RGB(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roverc
size_t max_serialized_size_roverc__msg__RGB(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roverc
bool cdr_serialize_key_roverc__msg__RGB(
  const roverc__msg__RGB * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roverc
size_t get_serialized_size_key_roverc__msg__RGB(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roverc
size_t max_serialized_size_key_roverc__msg__RGB(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roverc
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roverc, msg, RGB)();

#ifdef __cplusplus
}
#endif

#endif  // ROVERC__MSG__DETAIL__RGB__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
