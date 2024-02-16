// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/Vel.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__VEL__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__VEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/vel__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_Vel_vel
{
public:
  Init_Vel_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::msg::Vel vel(::my_interfaces::msg::Vel::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::Vel msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::Vel>()
{
  return my_interfaces::msg::builder::Init_Vel_vel();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__VEL__BUILDER_HPP_
