//SERVICE SERVER IN C++ WITH MY_INTERFACES
/*ros2 service call /result_service my_interfaces/srv/Result dist:\ 4\ */

/*This node is Service of "Result"*/
#include <chrono>
#include <cstdlib>
#include <memory>

//Standard C++ headers. These lines rapresent the node's dependencies.
#include "rclcpp/rclcpp.hpp"            
#include "my_interfaces/srv/result.hpp"    

class Robot_srv_server : public rclcpp::Node {
public:
    Robot_srv_server() : Node("robot_srv_server_node") {
        // Create a Service
        srv_ = create_service<my_interfaces::srv::Result>(
            "result_service", 
            std::bind(&Robot_srv_server::srv_callback, this, std::placeholders::_1, std::placeholders::_2));
    }

private:
    rclcpp::Service<my_interfaces::srv::Result>::SharedPtr srv_;

    // This serviceFunction is called when the service is called.
    void srv_callback(const std::shared_ptr<my_interfaces::srv::Result::Request> request,const std::shared_ptr<my_interfaces::srv::Result::Response> response) {
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
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "robot_srv_server_node ready!");  
    rclcpp::spin(std::make_shared<Robot_srv_server>());
    rclcpp::shutdown();
    return 0;
}
