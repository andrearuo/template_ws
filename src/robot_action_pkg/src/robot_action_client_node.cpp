//ACTION CLIENT IN C++ WITH MY_INTERFACES

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
#include "my_interfaces/action/fibonacci2.hpp"           

// Definitions
std::string node_name = "Robot_action_client_node";
std::string action_client_name = "fibonacci2";

//Create a class that is a derived class of rclcpp::Node
class Robot_action_client : public rclcpp::Node
{
public:
  //Used for the action client
  using Fibonacci2 = my_interfaces::action::Fibonacci2;
  using GoalHandleFibonacci2 = rclcpp_action::ClientGoalHandle<Fibonacci2>;


  //Initialize the node
  explicit Robot_action_client(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions()) : Node(node_name, node_options), goal_done_(false)
  {
    //Create the action client
    this->action_client_ = rclcpp_action::create_client<Fibonacci2>(
      this->get_node_base_interface(),
      this->get_node_graph_interface(),
      this->get_node_logging_interface(),
      this->get_node_waitables_interface(),
      action_client_name);

    //Create a timer to send the goal calling the send_goal function
    this->timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&Robot_action_client::send_goal, this));
  }

  bool is_goal_done() const
  {
    return this->goal_done_;
  }

  //Action client function----------------------------------------------
  void send_goal()
  {
    using namespace std::placeholders;
    //Cancels the timer (so it is only called once).
    this->timer_->cancel();

    this->goal_done_ = false;

    //Waits for the action server to come up.
    if (!this->action_client_) {
      RCLCPP_ERROR(rclcpp::get_logger("ACTION CLIENT"), "\nAction client not initialized");
    }

    //Cancel request after 10 seconds
    /*if (!this->action_client_->wait_for_action_server(std::chrono::seconds(10))) {
      RCLCPP_ERROR(rclcpp::get_logger("ACTION CLIENT"), "\nAction server not available after waiting");
      this->goal_done_ = true;
      return;
    }*/

    //Instantiates a new Fibonacci::Goal
    auto goal_msg = Fibonacci2::Goal();
    goal_msg.order2 = 10;
    RCLCPP_INFO(rclcpp::get_logger("ACTION CLIENT"), "Sending goal");

    //Sets the response, feedback, and result callbacks
    auto send_goal_options = rclcpp_action::Client<Fibonacci2>::SendGoalOptions();
    send_goal_options.goal_response_callback  =   std::bind(&Robot_action_client::goal_response_callback, this, _1);
    send_goal_options.feedback_callback       =   std::bind(&Robot_action_client::feedback_callback, this, _1, _2);
    send_goal_options.result_callback         =   std::bind(&Robot_action_client::result_callback, this, _1);
    
    //Sends the goal to the server
    auto goal_handle_future = this->action_client_->async_send_goal(goal_msg, send_goal_options);
  }
  //---------------------------------------------------------------------

private:
  //Used for the action client
  rclcpp_action::Client<Fibonacci2>::SharedPtr action_client_;
  rclcpp::TimerBase::SharedPtr timer_;
  bool goal_done_;

  //Action client callback functions-------------------------------------
  //When the server receives and accepts the goal, it will send a response to the client.
  //That response is handled by goal_response_callback
  void goal_response_callback(GoalHandleFibonacci2::SharedPtr goal_handle)
  {
    if (!goal_handle) {
      RCLCPP_ERROR(rclcpp::get_logger("ACTION CLIENT"), "\nGoal was rejected by server");
    } else {
      RCLCPP_INFO(rclcpp::get_logger("ACTION CLIENT"), "\nGoal accepted by server, waiting for result");
    }
  }

  //Assuming the goal was accepted by the server, it will start processing. 
  //Any feedback to the client will be handled by the feedback_callback
  void feedback_callback(GoalHandleFibonacci2::SharedPtr, const std::shared_ptr<const Fibonacci2::Feedback> feedback)
  {
    RCLCPP_INFO(rclcpp::get_logger("ACTION CLIENT"),"Next number in sequence received: %" PRId32, feedback->partial_sequence2.back());
  }

  //When the server is finished processing, it will return a result to the client. 
  //The result is handled by the result_callback
  void result_callback(const GoalHandleFibonacci2::WrappedResult & result)
  {
    this->goal_done_ = true;
    switch (result.code) {
      case rclcpp_action::ResultCode::SUCCEEDED:
        break;
      case rclcpp_action::ResultCode::ABORTED:
        RCLCPP_ERROR(rclcpp::get_logger("ACTION CLIENT"), "\nGoal was aborted");
        return;
      case rclcpp_action::ResultCode::CANCELED:
        RCLCPP_ERROR(rclcpp::get_logger("ACTION CLIENT"), "\nGoal was canceled");
        return;
      default:
        RCLCPP_ERROR(rclcpp::get_logger("ACTION CLIENT"), "\nUnknown result code");
        return;
    }

    RCLCPP_INFO(rclcpp::get_logger("ACTION CLIENT"), "Result received");
    for (auto number : result.result->sequence2) {
      RCLCPP_INFO(rclcpp::get_logger("ACTION CLIENT"), "%" PRId32, number);
    }
    //---------------------------------------------------------------------
  }
  
};  // class Robot_action_client

int main(int argc, char ** argv)
{
  //Initialize the ROS2 system
  rclcpp::init(argc, argv);
  
  // Debug info
  RCLCPP_INFO(rclcpp::get_logger(""), "\033[1;32m%s ready!\033[0m", node_name.c_str());
  RCLCPP_INFO(rclcpp::get_logger(""), "\033[1;32m%s CLIENT ready!\033[0m", action_client_name.c_str()); 

  //Create the action client
  auto action_client = std::make_shared<Robot_action_client>();

  //Wait for the action server to come up
  while (!action_client->is_goal_done()) {
    rclcpp::spin_some(action_client);
  }

  rclcpp::shutdown();
  return 0;
}
