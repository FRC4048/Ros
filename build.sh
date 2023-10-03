#/bin/sh

docker build --platform linux/arm64 -t ros-4048 .

docker save ros-4048 -o ros-4048.tar
