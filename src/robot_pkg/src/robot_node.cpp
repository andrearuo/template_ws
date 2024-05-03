//PUBLISHER AND SUBSCRIBER IN C++

#include <chrono>
#include <functional>
#include <memory>
#include <string>

//Standard C++ headers. These lines rapresent the node's dependencies.
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;
using std::placeholders::_1;

// Definitions
std::string node_name = "robot_node";
std::string publisher_name = "/vel";
std::string subscriber_name = "/dist";

// Node class creation
class Robot : public rclcpp::Node
{
  public:
    // Constructor initializes a Robot object:
    // - Creates a ROS 2 Node named "robot_node".
    // - Initializes a private member variable count_ to 0.
    Robot() : Node(node_name), count_(0)
    {
      // Publisher creation (with topic name, queue size to limit messages, and topic type)
      publisher_ = this->create_publisher<std_msgs::msg::String>(publisher_name, 10);
      
      // Timer inizialization in order to execute che timer_callback() function every 500ms 
      timer_ = this->create_wall_timer(500ms, std::bind(&Robot::timer_callback, this));
      
      // Subscription creation 
      subscription_ = this->create_subscription<std_msgs::msg::String>(subscriber_name, 10, std::bind(&Robot::topic_callback, this, _1));
    }

  private:
    // Private variables declaration
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    size_t count_;

    // Definition of the timer_callback() function.
    // This function is where the message data is set and the messages are published.
    void timer_callback()
    {
      auto message = std_msgs::msg::String();
      message.data = "Velocity: " + std::to_string(count_++);
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
    }

    void topic_callback(const std_msgs::msg::String & msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard, distance: '%s'", msg.data.c_str());
    }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "robot_node ready!");

  rclcpp::spin(std::make_shared<Robot>());
  rclcpp::shutdown();
  return 0;
}