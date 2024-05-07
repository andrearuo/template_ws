//PUBLISHER AND SUBSCRIBER IN C++ WITH MY_INTERFACES

#include <chrono>
#include <functional>
#include <memory>
#include <string>

//Standard C++ headers. These lines rapresent the node's dependencies.
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include "my_interfaces/msg/dist.hpp"   
#include "my_interfaces/msg/vel.hpp"  

using namespace std::chrono_literals;
using std::placeholders::_1;

// Definitions
std::string node_name = "robot_v2_node";
std::string publisher_name = "/vel";
std::string subscriber_name = "/dist";

// Node class creation
class Robot_v2 : public rclcpp::Node
{
  public:
    // Constructor initializes a Robot object:
    // - Creates a ROS 2 Node named "robot_node".
    // - Initializes a private member variable count_ to 0.
    Robot_v2() : Node(node_name), count_(0)
    {
      // Publisher creation (with topic name, queue size to limit messages, and topic type)
      publisher_ = this->create_publisher<my_interfaces::msg::Vel>(publisher_name, 10);
      // Timer inizialization in order to execute che timer_callback() function every 500ms 
      timer_ = this->create_wall_timer(500ms, std::bind(&Robot_v2::timer_callback, this));
      // Subscription creation 
      subscription_ = this->create_subscription<my_interfaces::msg::Dist>(subscriber_name, 10, std::bind(&Robot_v2::topic_callback, this, _1));
    }

  private:
    // Private variables declaration
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<my_interfaces::msg::Vel>::SharedPtr publisher_;
    rclcpp::Subscription<my_interfaces::msg::Dist>::SharedPtr subscription_;
    size_t count_;

    // Definition of the timer_callback() function.
    // This function is where the message data is set and the messages are published.
    void timer_callback()
    {
      auto message = my_interfaces::msg::Vel();
      message.vel = "Velocity: " + std::to_string(count_++);
      RCLCPP_INFO(rclcpp::get_logger("PUBLISHER"), "Publishing: '%s'", message.vel.c_str());
      publisher_->publish(message);
    }

    void topic_callback(const my_interfaces::msg::Dist & msg) const
    {
      RCLCPP_INFO(rclcpp::get_logger("SUBSCRIBER"), "I heard, distance: '%s'", msg.dist.c_str());
    }

    
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  
  // Debug info
  RCLCPP_INFO(rclcpp::get_logger(""), "\033[1;32m%s ready!\033[0m", node_name.c_str());
  
  rclcpp::spin(std::make_shared<Robot_v2>());
  rclcpp::shutdown();
  return 0;
}
