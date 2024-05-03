#PUBLISHER AND SUBSCRIBER IN PYTHON

#These lines represent the node’s dependencies
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

# Definitions
node_name = "camera_node"
publisher_name = "/dist"
subscriber_name = "/vel"

# Camera class Node creation
class Camera(Node):

    def __init__(self):
        # Node initialization
        super().__init__(node_name)
        
        # Publisher creation
        # Queue size is a required QoS setting that limits the amount of queued messages if a subscriber is not receiving them fast enough
        self.publisher_ = self.create_publisher(String, publisher_name, 10)
        
        # Subscription creation
        self.subscription = self.create_subscription(String, subscriber_name, self.listener_callback, 10)
        self.subscription  # prevent unused variable warning
        
        # Timer creation
        timer_period = 0.5  # seconds
        
        # Timer callback creation to execute every 500 ms
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = String()
        msg.data = 'Dist: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1

    def listener_callback(self, msg):
        self.get_logger().info('I heard vel: "%s"' % msg.data)

def main(args=None):
    rclpy.init(args=args)
    node = Camera()
    node.get_logger().info(node_name + ' ready!')


    rclpy.spin(node)
    node.destroy_node()
    
    rclpy.shutdown()


if __name__ == '__main__':
    main()