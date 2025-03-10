// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roverc:msg/WheelSpeed.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roverc/msg/wheel_speed.hpp"


#ifndef ROVERC__MSG__DETAIL__WHEEL_SPEED__TRAITS_HPP_
#define ROVERC__MSG__DETAIL__WHEEL_SPEED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "roverc/msg/detail/wheel_speed__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace roverc
{

namespace msg
{

inline void to_flow_style_yaml(
  const WheelSpeed & msg,
  std::ostream & out)
{
  out << "{";
  // member: front_right
  {
    out << "front_right: ";
    rosidl_generator_traits::value_to_yaml(msg.front_right, out);
    out << ", ";
  }

  // member: front_left
  {
    out << "front_left: ";
    rosidl_generator_traits::value_to_yaml(msg.front_left, out);
    out << ", ";
  }

  // member: rear_right
  {
    out << "rear_right: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_right, out);
    out << ", ";
  }

  // member: rear_left
  {
    out << "rear_left: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_left, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WheelSpeed & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: front_right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front_right: ";
    rosidl_generator_traits::value_to_yaml(msg.front_right, out);
    out << "\n";
  }

  // member: front_left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front_left: ";
    rosidl_generator_traits::value_to_yaml(msg.front_left, out);
    out << "\n";
  }

  // member: rear_right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rear_right: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_right, out);
    out << "\n";
  }

  // member: rear_left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rear_left: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_left, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WheelSpeed & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace roverc

namespace rosidl_generator_traits
{

[[deprecated("use roverc::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const roverc::msg::WheelSpeed & msg,
  std::ostream & out, size_t indentation = 0)
{
  roverc::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roverc::msg::to_yaml() instead")]]
inline std::string to_yaml(const roverc::msg::WheelSpeed & msg)
{
  return roverc::msg::to_yaml(msg);
}

template<>
inline const char * data_type<roverc::msg::WheelSpeed>()
{
  return "roverc::msg::WheelSpeed";
}

template<>
inline const char * name<roverc::msg::WheelSpeed>()
{
  return "roverc/msg/WheelSpeed";
}

template<>
struct has_fixed_size<roverc::msg::WheelSpeed>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<roverc::msg::WheelSpeed>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<roverc::msg::WheelSpeed>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROVERC__MSG__DETAIL__WHEEL_SPEED__TRAITS_HPP_
