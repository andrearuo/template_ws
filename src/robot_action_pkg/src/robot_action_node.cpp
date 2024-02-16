//ACTION SERVICE AND ACTION CLIENT IN C++ WITH MY_INTERFACES
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
#include "my_interfaces/action/fibonacci2.hpp"           

//Create a class that is a derived class of rclcpp::Node
class Robot_action : public rclcpp::Node
{
  public:
  //Used for the action server
  using Fibonacci = my_interfaces::action::Fibonacci;
  using GoalHandleFibonacci = rclcpp_action::ServerGoalHandle<Fibonacci>;
  //Used for the action client
  using Fibonacci2 = my_interfaces::action::Fibonacci2;
  using GoalHandleFibonacci2 = rclcpp_action::ClientGoalHandle<Fibonacci2>;


  //Initialize the node
  explicit Robot_action(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions()) : Node("robot_action_node", node_options), goal_done_(false)
  {
    //Used for the action server
    using namespace std::placeholders;
    
    //Create the action server
    this->action_server_ = rclcpp_action::create_server<Fibonacci>(
      this->get_node_base_interface(),
      this->get_node_clock_interface(),
      this->get_node_logging_interface(),
      this->get_node_waitables_interface(),
      "fibonacci",
      std::bind(&Robot_action::handle_goal, this, _1, _2),
      std::bind(&Robot_action::handle_cancel, this, _1),
      std::bind(&Robot_action::handle_accepted, this, _1));
  

    //Create the action client
    this->action_client_ = rclcpp_action::create_client<Fibonacci2>(
      this->get_node_base_interface(),
      this->get_node_graph_interface(),
      this->get_node_logging_interface(),
      this->get_node_waitables_interface(),
      "fibonacci2");

    //Create a timer to send the goal calling the send_goal function
    this->timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&Robot_action::send_goal, this));
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
      RCLCPP_ERROR(this->get_logger(), "Action client not initialized");
    }

    //Cancel request after s seconds
    /*if (!this->action_client_->wait_for_action_server(std::chrono::seconds(10))) {
      RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
      this->goal_done_ = true;
      return;
    }*/

    //Instantiates a new Fibonacci::Goal
    auto goal_msg = Fibonacci2::Goal();
    goal_msg.order2 = 10;
    RCLCPP_INFO(this->get_logger(), "Sending goal");

    //Sets the response, feedback, and result callbacks
    auto send_goal_options = rclcpp_action::Client<Fibonacci2>::SendGoalOptions();
    send_goal_options.goal_response_callback  =   std::bind(&Robot_action::goal_response_callback, this, _1);
    send_goal_options.feedback_callback       =   std::bind(&Robot_action::feedback_callback, this, _1, _2);
    send_goal_options.result_callback         =   std::bind(&Robot_action::result_callback, this, _1);
    
    //Sends the goal to the server
    auto goal_handle_future = this->action_client_->async_send_goal(goal_msg, send_goal_options);
  }
  //---------------------------------------------------------------------

  private:
  //Used for the action server
  rclcpp_action::Server<Fibonacci>::SharedPtr action_server_;

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
      RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
    } else {
      RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
    }
  }

  //Assuming the goal was accepted by the server, it will start processing. 
  //Any feedback to the client will be handled by the feedback_callback
  void feedback_callback(GoalHandleFibonacci2::SharedPtr, const std::shared_ptr<const Fibonacci2::Feedback> feedback)
  {
    RCLCPP_INFO(this->get_logger(),"Next number in sequence received: %" PRId32, feedback->partial_sequence2.back());
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
        RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
        return;
      case rclcpp_action::ResultCode::CANCELED:
        RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
        return;
      default:
        RCLCPP_ERROR(this->get_logger(), "Unknown result code");
        return;
    }

    RCLCPP_INFO(this->get_logger(), "Result received");
    for (auto number : result.result->sequence2) {
      RCLCPP_INFO(this->get_logger(), "%" PRId32, number);
    }
    //---------------------------------------------------------------------
  }
  //Action server functions---------------------------------------------
  rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const Fibonacci::Goal> goal)
  {
    RCLCPP_INFO(this->get_logger(), "Received goal request with order %d", goal->order);
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
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void execute(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Executing goal");
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
        RCLCPP_INFO(this->get_logger(), "Goal Canceled");
        return;
      }
      // Update sequence
      sequence.push_back(sequence[i] + sequence[i - 1]);
      // Publish feedback
      goal_handle->publish_feedback(feedback);
      RCLCPP_INFO(this->get_logger(), "Publish Feedback");

      loop_rate.sleep();
    }

    // Check if goal is done
    if (rclcpp::ok()) {
      result->sequence = sequence;
      goal_handle->succeed(result);
      RCLCPP_INFO(this->get_logger(), "Goal Succeeded");
    }
  }

  void handle_accepted(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
  {
    using namespace std::placeholders;
    // this needs to return quickly to avoid blocking the executor, so spin up a new thread
    std::thread{std::bind(&Robot_action::execute, this, _1), goal_handle}.detach();
  }
  //---------------------------------------------------------------------

};  // class Robot_action

int main(int argc, char ** argv)
{
  //Initialize the ROS2 system
  rclcpp::init(argc, argv);
  
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "robot_action_node ready!");        

  //Create the action client
  auto action_client = std::make_shared<Robot_action>();

  //Create the action server
  auto action_server = std::make_shared<Robot_action>();

  //Wait for the action server to come up
  while (!action_client->is_goal_done()) {
    rclcpp::spin_some(action_client);
  }

  //Spin the action server
  rclcpp::spin(action_server);


  rclcpp::shutdown();
  return 0;
}