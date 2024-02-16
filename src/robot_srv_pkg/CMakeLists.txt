cmake_minimum_required(VERSION 3.8)
project(robot_srv_pkg)

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
find_package(std_msgs REQUIRED)
find_package(my_interfaces REQUIRED) 
#  <-- ___________________________ -->

# Insert here your executables and ament_target_dependencies
add_executable(robot_srv_node src/robot_srv_node.cpp)
ament_target_dependencies(robot_srv_node rclcpp std_msgs my_interfaces)
add_executable(robot_srv_server_node src/robot_srv_server_node.cpp)
ament_target_dependencies(robot_srv_server_node rclcpp std_msgs my_interfaces)
add_executable(robot_srv_client_node src/robot_srv_client_node.cpp)
ament_target_dependencies(robot_srv_client_node rclcpp std_msgs my_interfaces)
#  <-- ___________________________ -->

install(TARGETS 
  # <-- Insert here your executables -->
  robot_srv_node
  robot_srv_server_node
  robot_srv_client_node
  #  <-- ___________________________ -->
  DESTINATION lib/${PROJECT_NAME})

ament_package()
