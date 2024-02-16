// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:srv/Result.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__SRV__DETAIL__RESULT__BUILDER_HPP_
#define MY_INTERFACES__SRV__DETAIL__RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/srv/detail/result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace srv
{

namespace builder
{

class Init_Result_Request_dist
{
public:
  Init_Result_Request_dist()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::srv::Result_Request dist(::my_interfaces::srv::Result_Request::_dist_type arg)
  {
    msg_.dist = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::srv::Result_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::srv::Result_Request>()
{
  return my_interfaces::srv::builder::Init_Result_Request_dist();
}

}  // namespace my_interfaces


namespace my_interfaces
{

namespace srv
{

namespace builder
{

class Init_Result_Response_result
{
public:
  Init_Result_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::srv::Result_Response result(::my_interfaces::srv::Result_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::srv::Result_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::srv::Result_Response>()
{
  return my_interfaces::srv::builder::Init_Result_Response_result();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__SRV__DETAIL__RESULT__BUILDER_HPP_
