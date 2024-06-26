#SERVER CLIENT IN PYTHON WITH MY_INTERFACES
# ros2 service call /add_three_ints_service my_interfaces/srv/AddThreeInts "{a: 0, b: 0, c: 5}"

#These lines represent the node’s dependencies   
import sys
import rclpy
from rclpy.node import Node
from my_interfaces.srv import Result

# Definitions
node_name = "camera_srv_client_node"
srv_client_name = "result_service"

# Camera class Node creation
class Camera_srv(Node):
    # Node initialization
    def __init__(self):
        super().__init__(node_name)
        
        # Client and Request creation
        self.srv_client = self.create_client(Result, srv_client_name)
        self.srv_client_req = Result.Request()
    
    # Call Service
    def CallService(self):
        self.srv_client_req.dist = 12

        # Wait For Service
        while not self.srv_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')

        # Call Service - Synchronous (Blocking - Critical)
        # response = self.srv_client.call(request)
        # self.get_logger().info(f'Response: {response}')

        # Call Service - Asynchronous
        self.future = self.srv_client.call_async(self.srv_client_req)
        rclpy.spin_until_future_complete(self, self.future)
        response_srv_client_req = self.future.result()
        self.get_logger().info('\nResponse received\nBool: %s' % (response_srv_client_req.result)) 



def main(args=None):
    rclpy.init(args=args)
    node = Camera_srv()
    node.get_logger().info(node_name + ' ready!')

    # Call a ROS Service Client
    node.CallService()

    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()
