// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from roverc:msg/RGB.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roverc/msg/rgb.hpp"


#ifndef ROVERC__MSG__DETAIL__RGB__STRUCT_HPP_
#define ROVERC__MSG__DETAIL__RGB__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__roverc__msg__RGB __attribute__((deprecated))
#else
# define DEPRECATED__roverc__msg__RGB __declspec(deprecated)
#endif

namespace roverc
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RGB_
{
  using Type = RGB_<ContainerAllocator>;

  explicit RGB_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->red = 0.0f;
      this->green = 0.0f;
      this->blue = 0.0f;
    }
  }

  explicit RGB_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->red = 0.0f;
      this->green = 0.0f;
      this->blue = 0.0f;
    }
  }

  // field types and members
  using _red_type =
    float;
  _red_type red;
  using _green_type =
    float;
  _green_type green;
  using _blue_type =
    float;
  _blue_type blue;

  // setters for named parameter idiom
  Type & set__red(
    const float & _arg)
  {
    this->red = _arg;
    return *this;
  }
  Type & set__green(
    const float & _arg)
  {
    this->green = _arg;
    return *this;
  }
  Type & set__blue(
    const float & _arg)
  {
    this->blue = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    roverc::msg::RGB_<ContainerAllocator> *;
  using ConstRawPtr =
    const roverc::msg::RGB_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roverc::msg::RGB_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roverc::msg::RGB_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roverc::msg::RGB_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roverc::msg::RGB_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roverc::msg::RGB_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roverc::msg::RGB_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roverc::msg::RGB_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roverc::msg::RGB_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roverc__msg__RGB
    std::shared_ptr<roverc::msg::RGB_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roverc__msg__RGB
    std::shared_ptr<roverc::msg::RGB_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RGB_ & other) const
  {
    if (this->red != other.red) {
      return false;
    }
    if (this->green != other.green) {
      return false;
    }
    if (this->blue != other.blue) {
      return false;
    }
    return true;
  }
  bool operator!=(const RGB_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RGB_

// alias to use template instance with default allocator
using RGB =
  roverc::msg::RGB_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace roverc

#endif  // ROVERC__MSG__DETAIL__RGB__STRUCT_HPP_
