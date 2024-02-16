// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:srv/Bool.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__SRV__DETAIL__BOOL__STRUCT_H_
#define MY_INTERFACES__SRV__DETAIL__BOOL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Bool in the package my_interfaces.
typedef struct my_interfaces__srv__Bool_Request
{
  int64_t dist;
} my_interfaces__srv__Bool_Request;

// Struct for a sequence of my_interfaces__srv__Bool_Request.
typedef struct my_interfaces__srv__Bool_Request__Sequence
{
  my_interfaces__srv__Bool_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__srv__Bool_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
#include "my_interfaces/msg/detail/bool__struct.h"

/// Struct defined in srv/Bool in the package my_interfaces.
typedef struct my_interfaces__srv__Bool_Response
{
  my_interfaces__msg__Bool result;
} my_interfaces__srv__Bool_Response;

// Struct for a sequence of my_interfaces__srv__Bool_Response.
typedef struct my_interfaces__srv__Bool_Response__Sequence
{
  my_interfaces__srv__Bool_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__srv__Bool_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__SRV__DETAIL__BOOL__STRUCT_H_
