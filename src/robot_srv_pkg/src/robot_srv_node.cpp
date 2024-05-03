//SERVICE SERVER AND SERVICE CLIENT IN C++ WITH MY_INTERFACES
/*ros2 service call /result_service my_interfaces/srv/Result dist:\ 4\ */

/*This node is Service of "Result" and Client of "AddThreeInts"*/
#include <chrono>
#include <cstdlib>
#include <memory>

//Standard C++ headers. These lines rapresent the node's dependencies.
#include "rclcpp/rclcpp.hpp"
#include "my_interfaces/srv/add_three_ints.hpp"              
#include "my_interfaces/srv/result.hpp"      

using namespace std::chrono_literals;

// Definitions
std::string node_name = "robot_srv_node";
std::string srv_server_name = "result_service";
std::string srv_client_name = "add_three_ints_service";

// This serviceFunction is called when the service is called.
void srv_callback(const std::shared_ptr<my_interfaces::srv::Result::Request> request, std::shared_ptr<my_interfaces::srv::Result::Response> response)  
{
  if (request->dist > 10)
  {
    response->result = true;
  }
  else
  {
    response->result = false;
  }

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\nIncoming request: \nDist: %ld", request->dist);                                         
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\nSending back response: \nBool: %d", response->result);
}

void CallService(rclcpp::Node::SharedPtr node, rclcpp::Client<my_interfaces::srv::AddThreeInts>::SharedPtr cli){
    // Service Request Creation
    auto request = std::make_shared<my_interfaces::srv::AddThreeInts::Request>();               
    request->a=1;
    request->b=2;
    request->c=3;  
      
    // Wait for Service to Start
    while (!cli -> wait_for_service(1s)) {
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service not available, waiting again...");
    }

    // Call Service
    auto result = cli -> async_send_request(request);

    // Wait for the Result
    if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS)
    {
      // Get and Print the Result
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\nResponse received\nsum: %ld", result.get()->sum);
    } else {
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Failed to call service add_three_ints");    
    }   
}


int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  //Creates a node named robot_srv_node
  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared(node_name);   

  //Creates a service named result_service
  rclcpp::Service<my_interfaces::srv::Result>::SharedPtr srv = node->create_service<my_interfaces::srv::Result>(srv_server_name,  &srv_callback);   

  //Creates a client named add_three_ints
  rclcpp::Client<my_interfaces::srv::AddThreeInts>::SharedPtr cli = node->create_client<my_interfaces::srv::AddThreeInts>(srv_client_name); 

  // Debug info
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "%s ready!", node_name.c_str());


  // Call a ROS Service Client
  CallService(node, cli);

  // Spin 
  rclcpp::spin(node);
  
  rclcpp::shutdown();
}
