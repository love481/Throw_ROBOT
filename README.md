# Throw_ROBOT
Autonomous code implemented in ros by integrating various pre-built and user-made packages for arrow throwing robot in robocon 2021.
Laptop or master devices is integrated with various sensors and microcontroller through ros which does the tasks of processings and act as the main_server while other microcontroller or slave devices just operate at hardware level for reading sensor data or outputing command to various actuators.
Here,You will find different packages which are given below:
## sensor_package:
handles joystick,Lidar,Encoder,IMU and so on.
## filters_algorithms package:
Handles path planning algorithm such as spline interpolation technique(min acceleration and jerk),bezier curve,A* algorithm and its smoothing algorithm,path tracking omni drive controller and so on.
## Actuators package:
Handles inverse kinematics for four wheeled omni drive robot,preprocessing of input encoder data using different pid controller methods and actuating the motors.
## Control package:
Contains contionous, discrete and fuzzy based pid controller and its implementation.
## Other packages:
Handles various other communication operations with stm32f4discovery board and with arduino uno and package to integrate lidar with server_computer and preprocess it to get the the line parameters of the static environment and so on.

