// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_interfaces:msg/Dist.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__DIST__TRAITS_HPP_
#define MY_INTERFACES__MSG__DETAIL__DIST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_interfaces/msg/detail/dist__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Dist & msg,
  std::ostream & out)
{
  out << "{";
  // member: dist
  {
    out << "dist: ";
    rosidl_generator_traits::value_to_yaml(msg.dist, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Dist & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: dist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist: ";
    rosidl_generator_traits::value_to_yaml(msg.dist, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Dist & msg, bool use_flow_style = false)
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

}  // namespace my_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_interfaces::msg::Dist & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::msg::Dist & msg)
{
  return my_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::msg::Dist>()
{
  return "my_interfaces::msg::Dist";
}

template<>
inline const char * name<my_interfaces::msg::Dist>()
{
  return "my_interfaces/msg/Dist";
}

template<>
struct has_fixed_size<my_interfaces::msg::Dist>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_interfaces::msg::Dist>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_interfaces::msg::Dist>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERFACES__MSG__DETAIL__DIST__TRAITS_HPP_
