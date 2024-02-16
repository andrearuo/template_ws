#SERVER CLIENT IN PYTHON WITH MY_INTERFACES
# ros2 service call /add_three_ints_service my_interfaces/srv/AddThreeInts "{a: 0, b: 0, c: 5}"

#These lines represent the node’s dependencies   
import sys
import rclpy
from rclpy.node import Node
from my_interfaces.srv import Result

# Camera class Node creation
class Camera_srv(Node):
    # Node initialization
    def __init__(self):
        super().__init__('camera_srv_node')
        
        # Client and Request creation
        self.cli = self.create_client(Result, 'result_service')
        self.req = Result.Request()
    
    # Call Service
    def CallService(self):
        self.req.dist = 12

        # Wait For Service
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')

        # Call Service - Synchronous (Blocking - Critical)
        # response = self.cli.call(request)
        # self.get_logger().info(f'Response: {response}')

        # Call Service - Asynchronous
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        response_req = self.future.result()
        self.get_logger().info('\nResponse received\nBool: %s' % (response_req.result)) 



def main(args=None):
    rclpy.init(args=args)
    node = Camera_srv()
    node.get_logger().info('camera_srv_client_node ready!')

    # Call a ROS Service Client
    node.CallService()

    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()