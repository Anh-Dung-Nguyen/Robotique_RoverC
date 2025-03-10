// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roverc:msg/RGB.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roverc/msg/rgb.hpp"


#ifndef ROVERC__MSG__DETAIL__RGB__BUILDER_HPP_
#define ROVERC__MSG__DETAIL__RGB__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "roverc/msg/detail/rgb__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace roverc
{

namespace msg
{

namespace builder
{

class Init_RGB_blue
{
public:
  explicit Init_RGB_blue(::roverc::msg::RGB & msg)
  : msg_(msg)
  {}
  ::roverc::msg::RGB blue(::roverc::msg::RGB::_blue_type arg)
  {
    msg_.blue = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roverc::msg::RGB msg_;
};

class Init_RGB_green
{
public:
  explicit Init_RGB_green(::roverc::msg::RGB & msg)
  : msg_(msg)
  {}
  Init_RGB_blue green(::roverc::msg::RGB::_green_type arg)
  {
    msg_.green = std::move(arg);
    return Init_RGB_blue(msg_);
  }

private:
  ::roverc::msg::RGB msg_;
};

class Init_RGB_red
{
public:
  Init_RGB_red()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RGB_green red(::roverc::msg::RGB::_red_type arg)
  {
    msg_.red = std::move(arg);
    return Init_RGB_green(msg_);
  }

private:
  ::roverc::msg::RGB msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::roverc::msg::RGB>()
{
  return roverc::msg::builder::Init_RGB_red();
}

}  // namespace roverc

#endif  // ROVERC__MSG__DETAIL__RGB__BUILDER_HPP_
