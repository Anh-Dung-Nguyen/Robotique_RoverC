// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from roverc:msg/RGB.idl
// generated code does not contain a copyright notice

#ifndef ROVERC__MSG__DETAIL__RGB__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ROVERC__MSG__DETAIL__RGB__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "roverc/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "roverc/msg/detail/rgb__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace roverc
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
cdr_serialize(
  const roverc::msg::RGB & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  roverc::msg::RGB & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
get_serialized_size(
  const roverc::msg::RGB & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
max_serialized_size_RGB(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
cdr_serialize_key(
  const roverc::msg::RGB & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
get_serialized_size_key(
  const roverc::msg::RGB & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
max_serialized_size_key_RGB(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace roverc

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, roverc, msg, RGB)();

#ifdef __cplusplus
}
#endif

#endif  // ROVERC__MSG__DETAIL__RGB__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
