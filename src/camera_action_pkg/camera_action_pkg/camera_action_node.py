#ACTION SERVICE AND ACTION CLIENT IN PYTHON WITH MY_INTERFACES
#ros2 action send_goal /fibonacci my_interfaces/action/Fibonacci order:\ 4\

import time

import rclpy
from rclpy.action import ActionServer
from rclpy.action import ActionClient
from rclpy.node import Node

from my_interfaces.action import Fibonacci
from my_interfaces.action import Fibonacci2

# Camera_action class, which is a subclass of the Node class
class Camera_action(Node):

    def __init__(self):
        # Node initialization
        super().__init__('camera_action_node')
        
        # Action server creation
        self._action_server = ActionServer(
            self,
            Fibonacci2,
            'fibonacci2',
            self.execute_callback)
        
        # Action client creation
        self._action_client = ActionClient(self, Fibonacci, 'fibonacci')
    
    # Callback function to execute the action server 
    # This is the method that will be called to execute a goal once it is accepted
    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')

        # Feedback message creation
        feedback_msg = Fibonacci2.Feedback()
        feedback_msg.partial_sequence2 = [0, 1]

        for i in range(1, goal_handle.request.order2):
            # Fibonacci sequence calculation
            feedback_msg.partial_sequence2.append(feedback_msg.partial_sequence2[i] + feedback_msg.partial_sequence2[i-1])
            self.get_logger().info('Feedback: {0}'.format(feedback_msg.partial_sequence2))
            # Publish the feedback message
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(1)

        # The goal is completed
        goal_handle.succeed()

        result = Fibonacci2.Result()
        result.sequence2 = feedback_msg.partial_sequence2
        return result

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
        #rclpy.shutdown()

    # This method is used to receive feedback from the action server
    def feedback_callback(self, feedback_msg):
            feedback = feedback_msg.feedback
            self.get_logger().info('Received feedback: {0}'.format(feedback.partial_sequence))

def main(args=None):
    rclpy.init(args=args)
    node = Camera_action()
    node.get_logger().info('camera_node ready!')

    # Send a goal to the action server
    node.send_goal(10)

    rclpy.spin(node)


if __name__ == '__main__':
    main()