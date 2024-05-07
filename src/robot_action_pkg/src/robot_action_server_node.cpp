//ACTION SERVICE IN C++ WITH MY_INTERFACES
/*ros2 action send_goal /fibonacci my_interfaces/action/Fibonacci order:\ 4\ */

#include <chrono>
#include <cinttypes>
#include <functional>
#include <future>
#include <memory>
#include <string>
#include <thread>

//Standard C++ headers. These lines rapresent the node's dependencies.
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "my_interfaces/action/fibonacci.hpp"            

// Definitions
std::string node_name = "robot_action_server_node";
std::string action_server_name = "fibonacci";

//Create a class that is a derived class of rclcpp::Node
class Robot_action_server : public rclcpp::Node
{
  public:
  //Used for the action server
  using Fibonacci = my_interfaces::action::Fibonacci;
  using GoalHandleFibonacci = rclcpp_action::ServerGoalHandle<Fibonacci>;
 
  //Initialize the node
  explicit Robot_action_server(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions()) : Node(node_name, node_options)
  {
    //Used for the action server
    using namespace std::placeholders;
    
    //Create the action server
    this->action_server_ = rclcpp_action::create_server<Fibonacci>(
      this->get_node_base_interface(),
      this->get_node_clock_interface(),
      this->get_node_logging_interface(),
      this->get_node_waitables_interface(),
      action_server_name,
      std::bind(&Robot_action_server::handle_goal, this, _1, _2),
      std::bind(&Robot_action_server::handle_cancel, this, _1),
      std::bind(&Robot_action_server::handle_accepted, this, _1));
  }


  private:
  //Used for the action server
  rclcpp_action::Server<Fibonacci>::SharedPtr action_server_;

  
  //Action server functions---------------------------------------------
  rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const Fibonacci::Goal> goal)
  {
    RCLCPP_INFO(rclcpp::get_logger("ACTION SERVER"), "Received goal request with order %d", goal->order);
    (void)uuid;
    // Let's reject sequences that are over 9000
    if (goal->order > 9000) {
      return rclcpp_action::GoalResponse::REJECT;
    }
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandleFibonacci> goal_handle)
  {
    RCLCPP_INFO(rclcpp::get_logger("ACTION SERVER"), "Received request to cancel goal");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void execute(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
  {
    RCLCPP_INFO(rclcpp::get_logger("ACTION SERVER"), "Executing goal");
    rclcpp::Rate loop_rate(1);
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<Fibonacci::Feedback>();
    auto & sequence = feedback->partial_sequence;
    sequence.push_back(0);
    sequence.push_back(1);
    auto result = std::make_shared<Fibonacci::Result>();

    for (int i = 1; (i < goal->order) && rclcpp::ok(); ++i) {
      // Check if there is a cancel request
      if (goal_handle->is_canceling()) {
        result->sequence = sequence;
        goal_handle->canceled(result);
        RCLCPP_INFO(rclcpp::get_logger("ACTION SERVER"), "Goal Canceled");
        return;
      }
      // Update sequence
      sequence.push_back(sequence[i] + sequence[i - 1]);
      // Publish feedback
      goal_handle->publish_feedback(feedback);
      RCLCPP_INFO(rclcpp::get_logger("ACTION SERVER"), "Publish Feedback");

      loop_rate.sleep();
    }

    // Check if goal is done
    if (rclcpp::ok()) {
      result->sequence = sequence;
      goal_handle->succeed(result);
      RCLCPP_INFO(rclcpp::get_logger("ACTION SERVER"), "Goal Succeeded");
    }
  }

  void handle_accepted(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
  {
    using namespace std::placeholders;
    // this needs to return quickly to avoid blocking the executor, so spin up a new thread
    std::thread{std::bind(&Robot_action_server::execute, this, _1), goal_handle}.detach();
  }
  //---------------------------------------------------------------------

};  // class Robot_action_server

int main(int argc, char ** argv)
{
  //Initialize the ROS2 system
  rclcpp::init(argc, argv);

  // Debug info
  RCLCPP_INFO(rclcpp::get_logger(""), "\033[1;32m%s ready!\033[0m", node_name.c_str());
  RCLCPP_INFO(rclcpp::get_logger(""), "\033[1;32m%s SERVER ready!\033[0m", action_server_name.c_str());  

  //Create the action server
  auto action_server = std::make_shared<Robot_action_server>();

  //Spin the action server
  rclcpp::spin(action_server);

  rclcpp::shutdown();
  return 0;
}
