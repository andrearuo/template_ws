# ROS2 GUIDE
>:warning: Ubuntu 22.04, ROS2 Humble

>:pencil: Andrea Ruo

## Packages topology
This is a template workspace in which there are different types of packages. The packages are:
- ``camera_pkg``: in this package there is a publisher and a subscriber in pyhton.
- ``robot_pkg``: in this package there is a publisher and a subscriber in c++.

- ``my_interfaces``: in this package there are the msg and srv files.

- ``camera_v2_pkg``: is ``camera_pkg`` but uses msg files.
- ``robot_v2_pkg``: is ``robot_pkg`` but uses msg files.

- ``camera_srv_pkg``: in this package there is a service and a client in python.
- ``robot_srv_pkg``: in this package there is a service and a client in c++.

- ``camera_action_pkg``: in this package there is a action service and a action client in python.
- ``robot_action_pkg``: in this package there is a action service and a action client in c++.

## How to use it
- First demo (topics):
```bash
# Terminal 1
ros2 run camera_pkg camera_node

# Terminal 2
ros2 run robot_pkg robot_node
```

- Second demo (topics with my_interfaces):
```bash
# Terminal 1
ros2 run camera_v2_pkg camera_v2_node

# Terminal 2
ros2 run robot_v2_pkg robot_v2_node
```

- Third demo (services):
```bash
# Terminal 1
ros2 run camera_srv_pkg camera_srv_server_node

# Terminal 2
ros2 run robot_srv_pkg robot_srv_client_node
```
and then

```bash
# Terminal 1
ros2 run robot_srv_pkg robot_srv_server_node

# Terminal 2
ros2 run camera_srv_pkg camera_srv_client_node
```


- Third demo (actions):
```bash
# Terminal 1
ros2 run camera_action_pkg camera_action_server_node

# Terminal 2
ros2 run robot_action_pkg robot_action_client_node
```
and then

```bash
# Terminal 1
ros2 run robot_action_pkg robot_action_server_node

# Terminal 2
ros2 run camera_action_pkg camera_action_client_node
```

## Guide
Inside the ``GUIDE`` folder there is a guide that explains how to create a package, how to create a publisher and a subscriber, how to create a service and a client, how to create an action service and a action client, and how to use msg and srv files.