#
# Dockerfile for the ros image to be used on the Raspberrypi
#

FROM ros:melodic-ros-core
RUN apt update && apt install -y build-essential
RUN apt update && apt install -y ros-melodic-tf
# setup ros packages
#------------------------
# Change the default shell to Bash
SHELL [ "/bin/bash" , "-c" ]
#setup catkin
RUN source /opt/ros/melodic/setup.bash \
    && mkdir -p /catkin_ws/src \
    && cd /catkin_ws/src \
    && catkin_init_workspace
#------------------------
# matlab    
COPY amcl-matlab /catkin_ws/
RUN source /opt/ros/melodic/setup.bash \
    && cd /catkin_ws/ \
    && catkin_make
#setup rp lidar
#------------------------
RUN source /opt/ros/melodic/setup.bash \
    && mkdir -p /catkin_ws/src/rplidar_ros
COPY ./rplidar_ros /catkin_ws/src/rplidar_ros
RUN source /opt/ros/melodic/setup.bash \
    && cd /catkin_ws/ \
    && catkin_make
RUN echo "source /catkin_ws/devel/setup.bash" >> ~/.bashrc
#------------------------

# setup for tf tree
RUN source /opt/ros/melodic/setup.bash \
    && cd /catkin_ws/src \
    && catkin_create_pkg test_launch std_msgs rospy roscpp
RUN mkdir -p /catkin_ws/src/test_launch/launch
COPY base_test.launch /catkin_ws/src/test_launch/launch
RUN source /opt/ros/melodic/setup.bash \
    && cd /catkin_ws/ \
    && catkin_make
# gmapping
SHELL ["/bin/sh", "-c"]
RUN apt update && apt install -y ros-melodic-hector-slam
WORKDIR ros_scripts
COPY *.sh .

