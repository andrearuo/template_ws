//SERVICE SERVER IN C++ WITH MY_INTERFACES
/*ros2 service call /result_service my_interfaces/srv/Result dist:\ 4\ */

/*This node is Service of "Result"*/
#include <chrono>
#include <cstdlib>
#include <memory>

//Standard C++ headers. These lines rapresent the node's dependencies.
#include "rclcpp/rclcpp.hpp"            
#include "my_interfaces/srv/result.hpp"    

// Definitions
std::string node_name = "robot_srv_server_node";
std::string srv_server_name = "result_service";

class Robot_srv_server : public rclcpp::Node {
public:
    Robot_srv_server() : Node(node_name) {
        // Create a Service
        srv_server_ = create_service<my_interfaces::srv::Result>(srv_server_name, std::bind(&Robot_srv_server::srv_server_callback, this, std::placeholders::_1, std::placeholders::_2));
    }

private:
    rclcpp::Service<my_interfaces::srv::Result>::SharedPtr srv_server_;

    // This serviceFunction is called when the service is called.
    void srv_server_callback(const std::shared_ptr<my_interfaces::srv::Result::Request> request,const std::shared_ptr<my_interfaces::srv::Result::Response> response) {
        if (request->dist > 10)
        {
            response->result = true;
        }
        else
        {
            response->result = false;
        }

	RCLCPP_INFO(rclcpp::get_logger("SERVICE SERVER"), "\033[1;32mIncoming request:\033[0m");
        RCLCPP_INFO(rclcpp::get_logger("SERVICE SERVER"), "Dist: %ld", request->dist);                                         
        RCLCPP_INFO(rclcpp::get_logger("SERVICE SERVER"), "\033[1;32mSending back response:\033[0m");
        RCLCPP_INFO(rclcpp::get_logger("SERVICE SERVER"), "Bool: %d", response->result);
    }
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    
    // Debug info
    RCLCPP_INFO(rclcpp::get_logger(""), "\033[1;32m%s ready!\033[0m", node_name.c_str());
    RCLCPP_INFO(rclcpp::get_logger(""), "\033[1;32m%s SERVER ready!\033[0m", srv_server_name.c_str());  

    rclcpp::spin(std::make_shared<Robot_srv_server>());
    rclcpp::shutdown();
    return 0;
}
