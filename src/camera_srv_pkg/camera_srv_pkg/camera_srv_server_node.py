#SERVICE SERVER IN PYTHON WITH MY_INTERFACES
# ros2 service call /add_three_ints_service my_interfaces/srv/AddThreeInts "{a: 0, b: 0, c: 5}"

#These lines represent the node’s dependencies   
import sys
import rclpy
from rclpy.node import Node
from my_interfaces.srv import AddThreeInts 

# Camera class Node creation
class Camera_srv(Node):
    # Node initialization
    def __init__(self):
        super().__init__('camera_srv_node')
        
        # Service creation with type, name, and callback definitions.
        self.srv = self.create_service(AddThreeInts, 'add_three_ints_service', self.srv_callback)        
        
    # Service Callback
    def srv_callback(self, request, response):
        response.sum = request.a + request.b + request.c                                                  
        self.get_logger().info('\nIncoming request\na: %d b: %d c: %d' % (request.a, request.b, request.c)) 
        self.get_logger().info('\nSending response\nsum: %d' % (response.sum)) 

        return response



def main(args=None):
    rclpy.init(args=args)
    node = Camera_srv()
    node.get_logger().info('camera_srv_server_node ready!')

    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()