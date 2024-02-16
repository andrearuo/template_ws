// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/Dist.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__DIST__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__DIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/dist__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_Dist_dist
{
public:
  Init_Dist_dist()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::msg::Dist dist(::my_interfaces::msg::Dist::_dist_type arg)
  {
    msg_.dist = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::Dist msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::Dist>()
{
  return my_interfaces::msg::builder::Init_Dist_dist();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__DIST__BUILDER_HPP_
