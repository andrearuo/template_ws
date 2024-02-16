#ACTION SERVICE IN PYTHON WITH MY_INTERFACES
#ros2 action send_goal /fibonacci my_interfaces/action/Fibonacci order:\ 4\

import time

import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node

from my_interfaces.action import Fibonacci2

# Camera_action_server class, which is a subclass of the Node class
class Camera_action_server(Node):

    def __init__(self):
        # Node initialization
        super().__init__('camera_action_server_node')
        
        # Action server creation
        self._action_server = ActionServer(
            self,
            Fibonacci2,
            'fibonacci2',
            self.execute_callback)
    
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


def main(args=None):
    rclpy.init(args=args)
    node = Camera_action_server()
    node.get_logger().info('camera_node ready!')

    rclpy.spin(node)


if __name__ == '__main__':
    main()