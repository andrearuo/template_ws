// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:srv/Bool.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__SRV__DETAIL__BOOL__STRUCT_HPP_
#define MY_INTERFACES__SRV__DETAIL__BOOL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_interfaces__srv__Bool_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__srv__Bool_Request __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Bool_Request_
{
  using Type = Bool_Request_<ContainerAllocator>;

  explicit Bool_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dist = 0ll;
    }
  }

  explicit Bool_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dist = 0ll;
    }
  }

  // field types and members
  using _dist_type =
    int64_t;
  _dist_type dist;

  // setters for named parameter idiom
  Type & set__dist(
    const int64_t & _arg)
  {
    this->dist = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_interfaces::srv::Bool_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::srv::Bool_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::srv::Bool_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::srv::Bool_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::srv::Bool_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::srv::Bool_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::srv::Bool_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::srv::Bool_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::srv::Bool_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::srv::Bool_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__srv__Bool_Request
    std::shared_ptr<my_interfaces::srv::Bool_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__srv__Bool_Request
    std::shared_ptr<my_interfaces::srv::Bool_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Bool_Request_ & other) const
  {
    if (this->dist != other.dist) {
      return false;
    }
    return true;
  }
  bool operator!=(const Bool_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Bool_Request_

// alias to use template instance with default allocator
using Bool_Request =
  my_interfaces::srv::Bool_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_interfaces


// Include directives for member types
// Member 'result'
#include "my_interfaces/msg/detail/bool__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_interfaces__srv__Bool_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__srv__Bool_Response __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Bool_Response_
{
  using Type = Bool_Response_<ContainerAllocator>;

  explicit Bool_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    (void)_init;
  }

  explicit Bool_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _result_type =
    my_interfaces::msg::Bool_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const my_interfaces::msg::Bool_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_interfaces::srv::Bool_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::srv::Bool_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::srv::Bool_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::srv::Bool_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::srv::Bool_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::srv::Bool_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::srv::Bool_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::srv::Bool_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::srv::Bool_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::srv::Bool_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__srv__Bool_Response
    std::shared_ptr<my_interfaces::srv::Bool_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__srv__Bool_Response
    std::shared_ptr<my_interfaces::srv::Bool_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Bool_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Bool_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Bool_Response_

// alias to use template instance with default allocator
using Bool_Response =
  my_interfaces::srv::Bool_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_interfaces

namespace my_interfaces
{

namespace srv
{

struct Bool
{
  using Request = my_interfaces::srv::Bool_Request;
  using Response = my_interfaces::srv::Bool_Response;
};

}  // namespace srv

}  // namespace my_interfaces

#endif  // MY_INTERFACES__SRV__DETAIL__BOOL__STRUCT_HPP_
