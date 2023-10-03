#
# Dockerfile for the ros image to be used on the Jetson
#

FROM ros:melodic-ros-core

WORKDIR ros_scripts

RUN apt update
RUN apt install ros-melodic-rplidar-ros
RUN apt update
RUN apt install -y --no-install-recommends ros-melodic-gmapping

COPY *.sh .
