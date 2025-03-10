// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from roverc:msg/WheelSpeed.idl
// generated code does not contain a copyright notice
#include "roverc/msg/detail/wheel_speed__rosidl_typesupport_fastrtps_cpp.hpp"
#include "roverc/msg/detail/wheel_speed__functions.h"
#include "roverc/msg/detail/wheel_speed__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace roverc
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
cdr_serialize(
  const roverc::msg::WheelSpeed & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: front_right
  cdr << ros_message.front_right;

  // Member: front_left
  cdr << ros_message.front_left;

  // Member: rear_right
  cdr << ros_message.rear_right;

  // Member: rear_left
  cdr << ros_message.rear_left;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  roverc::msg::WheelSpeed & ros_message)
{
  // Member: front_right
  cdr >> ros_message.front_right;

  // Member: front_left
  cdr >> ros_message.front_left;

  // Member: rear_right
  cdr >> ros_message.rear_right;

  // Member: rear_left
  cdr >> ros_message.rear_left;

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
get_serialized_size(
  const roverc::msg::WheelSpeed & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: front_right
  {
    size_t item_size = sizeof(ros_message.front_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: front_left
  {
    size_t item_size = sizeof(ros_message.front_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rear_right
  {
    size_t item_size = sizeof(ros_message.rear_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rear_left
  {
    size_t item_size = sizeof(ros_message.rear_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
max_serialized_size_WheelSpeed(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: front_right
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: front_left
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: rear_right
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: rear_left
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = roverc::msg::WheelSpeed;
    is_plain =
      (
      offsetof(DataType, rear_left) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
cdr_serialize_key(
  const roverc::msg::WheelSpeed & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: front_right
  cdr << ros_message.front_right;

  // Member: front_left
  cdr << ros_message.front_left;

  // Member: rear_right
  cdr << ros_message.rear_right;

  // Member: rear_left
  cdr << ros_message.rear_left;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
get_serialized_size_key(
  const roverc::msg::WheelSpeed & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: front_right
  {
    size_t item_size = sizeof(ros_message.front_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: front_left
  {
    size_t item_size = sizeof(ros_message.front_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rear_right
  {
    size_t item_size = sizeof(ros_message.rear_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rear_left
  {
    size_t item_size = sizeof(ros_message.rear_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_roverc
max_serialized_size_key_WheelSpeed(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: front_right
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: front_left
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rear_right
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rear_left
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = roverc::msg::WheelSpeed;
    is_plain =
      (
      offsetof(DataType, rear_left) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _WheelSpeed__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const roverc::msg::WheelSpeed *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _WheelSpeed__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<roverc::msg::WheelSpeed *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _WheelSpeed__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const roverc::msg::WheelSpeed *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _WheelSpeed__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_WheelSpeed(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _WheelSpeed__callbacks = {
  "roverc::msg",
  "WheelSpeed",
  _WheelSpeed__cdr_serialize,
  _WheelSpeed__cdr_deserialize,
  _WheelSpeed__get_serialized_size,
  _WheelSpeed__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _WheelSpeed__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_WheelSpeed__callbacks,
  get_message_typesupport_handle_function,
  &roverc__msg__WheelSpeed__get_type_hash,
  &roverc__msg__WheelSpeed__get_type_description,
  &roverc__msg__WheelSpeed__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace roverc

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_roverc
const rosidl_message_type_support_t *
get_message_type_support_handle<roverc::msg::WheelSpeed>()
{
  return &roverc::msg::typesupport_fastrtps_cpp::_WheelSpeed__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, roverc, msg, WheelSpeed)() {
  return &roverc::msg::typesupport_fastrtps_cpp::_WheelSpeed__handle;
}

#ifdef __cplusplus
}
#endif
