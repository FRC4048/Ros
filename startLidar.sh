#!/bin/bash
source /opt/ros/melodic/setup.bash
sudo chmod 666 /dev/ttyUSB0
roslaunch rplidar_ros rplidar.launch
