// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/Dist.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__DIST__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__DIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'dist'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Dist in the package my_interfaces.
typedef struct my_interfaces__msg__Dist
{
  rosidl_runtime_c__String dist;
} my_interfaces__msg__Dist;

// Struct for a sequence of my_interfaces__msg__Dist.
typedef struct my_interfaces__msg__Dist__Sequence
{
  my_interfaces__msg__Dist * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__Dist__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__DIST__STRUCT_H_
