// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_interfaces:srv/Bool.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__SRV__DETAIL__BOOL__TRAITS_HPP_
#define MY_INTERFACES__SRV__DETAIL__BOOL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_interfaces/srv/detail/bool__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Bool_Request & msg,
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
  const Bool_Request & msg,
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

inline std::string to_yaml(const Bool_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_interfaces::srv::Bool_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::srv::Bool_Request & msg)
{
  return my_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::srv::Bool_Request>()
{
  return "my_interfaces::srv::Bool_Request";
}

template<>
inline const char * name<my_interfaces::srv::Bool_Request>()
{
  return "my_interfaces/srv/Bool_Request";
}

template<>
struct has_fixed_size<my_interfaces::srv::Bool_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_interfaces::srv::Bool_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_interfaces::srv::Bool_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
#include "my_interfaces/msg/detail/bool__traits.hpp"

namespace my_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Bool_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Bool_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Bool_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_interfaces::srv::Bool_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::srv::Bool_Response & msg)
{
  return my_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::srv::Bool_Response>()
{
  return "my_interfaces::srv::Bool_Response";
}

template<>
inline const char * name<my_interfaces::srv::Bool_Response>()
{
  return "my_interfaces/srv/Bool_Response";
}

template<>
struct has_fixed_size<my_interfaces::srv::Bool_Response>
  : std::integral_constant<bool, has_fixed_size<my_interfaces::msg::Bool>::value> {};

template<>
struct has_bounded_size<my_interfaces::srv::Bool_Response>
  : std::integral_constant<bool, has_bounded_size<my_interfaces::msg::Bool>::value> {};

template<>
struct is_message<my_interfaces::srv::Bool_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_interfaces::srv::Bool>()
{
  return "my_interfaces::srv::Bool";
}

template<>
inline const char * name<my_interfaces::srv::Bool>()
{
  return "my_interfaces/srv/Bool";
}

template<>
struct has_fixed_size<my_interfaces::srv::Bool>
  : std::integral_constant<
    bool,
    has_fixed_size<my_interfaces::srv::Bool_Request>::value &&
    has_fixed_size<my_interfaces::srv::Bool_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_interfaces::srv::Bool>
  : std::integral_constant<
    bool,
    has_bounded_size<my_interfaces::srv::Bool_Request>::value &&
    has_bounded_size<my_interfaces::srv::Bool_Response>::value
  >
{
};

template<>
struct is_service<my_interfaces::srv::Bool>
  : std::true_type
{
};

template<>
struct is_service_request<my_interfaces::srv::Bool_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_interfaces::srv::Bool_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERFACES__SRV__DETAIL__BOOL__TRAITS_HPP_
