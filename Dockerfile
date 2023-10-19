#
# Dockerfile for the ros image to be used on the Jetson
#

FROM ros:melodic-ros-core

WORKDIR ros_scripts

RUN apt update
RUN apt install ros-melodic-rplidar-ros
RUN apt update
RUN apt install -y --no-install-recommends ros-melodic-gmapping
#setup ros packages
RUN mkdir -p ~/catkin_ws/src
#setup rp lidar
RUN cd ~/catkin_ws/src
COPY ./rplidar_ros ~/catkin_ws/src/
RUN mkdir ~/catkin_ws/
RUN catkin_make
RUN echo "source $HOME/catkin_ws/devel/setup.bash" >> ~/.bashrc
# setup for tf tree
RUN cd ~/catkin_ws/src
RUN catkin_create_pkg test_launch std_msgs rospy roscpp
RUN mkdir -p ~/catkin_ws/src/launch
COPY base_test.launch ~/catkin_ws/src/launch/
RUN mkdir ~/catkin_ws/
RUN catkin_make


COPY *.sh .
