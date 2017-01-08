#!/bin/bash

source /opt/ros/indigo/setup.bash
source devel/setup.bash

#export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:./gazebo/models
#export GAZEBO_RESOURCE_PATH=$GAZEBO_RESOURCE_PATH:./gazebo:./gazebo/worlds

#roslaunch husky_simulator test.launch
gazebo gazebo/worlds/saved.world
