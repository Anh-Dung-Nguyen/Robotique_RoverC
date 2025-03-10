// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roverc:msg/WheelSpeed.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roverc/msg/wheel_speed.hpp"


#ifndef ROVERC__MSG__DETAIL__WHEEL_SPEED__BUILDER_HPP_
#define ROVERC__MSG__DETAIL__WHEEL_SPEED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "roverc/msg/detail/wheel_speed__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace roverc
{

namespace msg
{

namespace builder
{

class Init_WheelSpeed_rear_left
{
public:
  explicit Init_WheelSpeed_rear_left(::roverc::msg::WheelSpeed & msg)
  : msg_(msg)
  {}
  ::roverc::msg::WheelSpeed rear_left(::roverc::msg::WheelSpeed::_rear_left_type arg)
  {
    msg_.rear_left = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roverc::msg::WheelSpeed msg_;
};

class Init_WheelSpeed_rear_right
{
public:
  explicit Init_WheelSpeed_rear_right(::roverc::msg::WheelSpeed & msg)
  : msg_(msg)
  {}
  Init_WheelSpeed_rear_left rear_right(::roverc::msg::WheelSpeed::_rear_right_type arg)
  {
    msg_.rear_right = std::move(arg);
    return Init_WheelSpeed_rear_left(msg_);
  }

private:
  ::roverc::msg::WheelSpeed msg_;
};

class Init_WheelSpeed_front_left
{
public:
  explicit Init_WheelSpeed_front_left(::roverc::msg::WheelSpeed & msg)
  : msg_(msg)
  {}
  Init_WheelSpeed_rear_right front_left(::roverc::msg::WheelSpeed::_front_left_type arg)
  {
    msg_.front_left = std::move(arg);
    return Init_WheelSpeed_rear_right(msg_);
  }

private:
  ::roverc::msg::WheelSpeed msg_;
};

class Init_WheelSpeed_front_right
{
public:
  Init_WheelSpeed_front_right()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WheelSpeed_front_left front_right(::roverc::msg::WheelSpeed::_front_right_type arg)
  {
    msg_.front_right = std::move(arg);
    return Init_WheelSpeed_front_left(msg_);
  }

private:
  ::roverc::msg::WheelSpeed msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::roverc::msg::WheelSpeed>()
{
  return roverc::msg::builder::Init_WheelSpeed_front_right();
}

}  // namespace roverc

#endif  // ROVERC__MSG__DETAIL__WHEEL_SPEED__BUILDER_HPP_
