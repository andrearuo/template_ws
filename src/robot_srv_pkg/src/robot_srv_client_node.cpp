//SERVICE CLIENT IN C++ WITH MY_INTERFACES

/*This node is Client of "AddThreeInts"*/
#include <chrono>
#include <cstdlib>
#include <memory>

//Standard C++ headers. These lines rapresent the node's dependencies.
#include "rclcpp/rclcpp.hpp"
#include "my_interfaces/srv/add_three_ints.hpp"              
#include "my_interfaces/srv/result.hpp"   

using namespace std::chrono_literals;

// Definitions
std::string node_name = "robot_srv_client_node";
std::string srv_client_name = "add_three_ints_service";

class Robot_srv_client : public rclcpp::Node {
public:
    Robot_srv_client() : Node(node_name) {
        client_ = this->create_client<my_interfaces::srv::AddThreeInts>(srv_client_name);
        timer_ = this->create_wall_timer(1s, std::bind(&Robot_srv_client::timer_callback, this));
    }

    bool is_service_done() const {
        return this->service_done_;
    }

private:
    rclcpp::Client<my_interfaces::srv::AddThreeInts>::SharedPtr client_;
    rclcpp::TimerBase::SharedPtr timer_;
    bool service_done_ = false; 

    void timer_callback() {
        // Service Request Creation
        auto request = std::make_shared<my_interfaces::srv::AddThreeInts::Request>();               
        request->a=1;
        request->b=2;
        request->c=3;  

        // Wait for Service to Start
        while (!client_ -> wait_for_service(1s)) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service not available, waiting again...");
        }

        // Call Service
        auto result = client_ -> async_send_request(request,std::bind(&Robot_srv_client::response_callback, this, std::placeholders::_1));
    }

    
    void response_callback(rclcpp::Client<my_interfaces::srv::AddThreeInts>::SharedFuture future) {
        auto status = future.wait_for(1s);

        if (status == std::future_status::ready) {
            auto result = future.get();
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\nResponse received\nsum: %ld", result.get()->sum);
            service_done_ = true;
        } else {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Failed to call service add_three_ints");
        }

    }
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);

    // Debug info
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "%s ready!", node_name.c_str());

    auto client = std::make_shared<Robot_srv_client>();

    while (!client->is_service_done()) {
        rclcpp::spin_some(client);
    }

    rclcpp::shutdown();
    return 0;
}
