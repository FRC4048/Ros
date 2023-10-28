#!/bin/bash
sudo chmod 666 /dev/ttyUSB0
roslaunch rplidar_ros rplidar_a2m8.launch --wait
