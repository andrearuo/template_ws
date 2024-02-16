cmake_minimum_required(VERSION 3.8)
project(robot_action_pkg)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# <-- Insert here your dependences -->
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(my_interfaces REQUIRED) 
#  <-- ___________________________ -->

# Insert here your executables and ament_target_dependencies
add_executable(robot_action_node src/robot_action_node.cpp)
ament_target_dependencies(robot_action_node rclcpp rclcpp_action rclcpp_components std_msgs my_interfaces)
add_executable(robot_action_client_node src/robot_action_client_node.cpp)
ament_target_dependencies(robot_action_client_node rclcpp rclcpp_action rclcpp_components std_msgs my_interfaces)
add_executable(robot_action_server_node src/robot_action_server_node.cpp)
ament_target_dependencies(robot_action_server_node rclcpp rclcpp_action rclcpp_components std_msgs my_interfaces)


#  <-- ___________________________ -->


install(TARGETS 
  # <-- Insert here your executables -->
  robot_action_node
  robot_action_client_node
  robot_action_server_node

  #  <-- ___________________________ -->
  DESTINATION lib/${PROJECT_NAME})

ament_package()
