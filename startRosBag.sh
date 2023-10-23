#!/bin/bash
source /opt/ros/melodic/setup.bash
mkdir -p /media/bzeliger/BOBBA/rosbags
cd /media/bzeliger/BOBBA/rosbags
rosbag record -a
