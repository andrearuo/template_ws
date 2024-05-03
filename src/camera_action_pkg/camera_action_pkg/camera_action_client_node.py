#ACTION CLIENT IN PYTHON WITH MY_INTERFACES

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from my_interfaces.action import Fibonacci

# Definitions
node_name = "camera_action_client_node"
action_client_name = "fibonacci"

# Camera_action_client class, which is a subclass of the Node class
class Camera_action_client(Node):
    # Node initialization
    def __init__(self):
        super().__init__(node_name)
        
        # Action client creation
        self._action_client = ActionClient(self, Fibonacci, action_client_name)

    #This method waits for the action server to be available, then sends a goal to the server. 
    def send_goal(self, order):
        # Goal message creation
        goal_msg = Fibonacci.Goal()
        goal_msg.order = order

        # Wait for the action server to be available
        self._action_client.wait_for_server()
        # Send the goal to the action server 
        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        # Register a callback for when the future is complete
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    # This method checks if the goal was rejected or accepted.
    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')

        # Request the result of the goal
        self._get_result_future = goal_handle.get_result_async()
        # Register a callback for when the future is complete
        self._get_result_future.add_done_callback(self.get_result_callback)

    # Log the result sequence and shutdown ROS 2 for a clean exit
    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Result: {0}'.format(result.sequence))
        rclpy.shutdown()

    # This method is used to receive feedback from the action server
    def feedback_callback(self, feedback_msg):
            feedback = feedback_msg.feedback
            self.get_logger().info('Received feedback: {0}'.format(feedback.partial_sequence))


def main(args=None):
    rclpy.init(args=args)
    node = Camera_action_client()
    node.get_logger().info(node_name + ' ready!')

    # Send a goal to the action server
    node.send_goal(10)

    # Wait for the goal to be accepted
    rclpy.spin(node)



if __name__ == '__main__':
    main()