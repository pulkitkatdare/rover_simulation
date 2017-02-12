# Install script for directory: /home/dhruv-shah/ros_ws/rover_simulation/husky_test/src/husky_navigation

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/dhruv-shah/ros_ws/rover_simulation/husky_test/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/dhruv-shah/ros_ws/rover_simulation/husky_test/build/husky_navigation/catkin_generated/installspace/husky_navigation.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/husky_navigation/cmake" TYPE FILE FILES
    "/home/dhruv-shah/ros_ws/rover_simulation/husky_test/build/husky_navigation/catkin_generated/installspace/husky_navigationConfig.cmake"
    "/home/dhruv-shah/ros_ws/rover_simulation/husky_test/build/husky_navigation/catkin_generated/installspace/husky_navigationConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/husky_navigation" TYPE FILE FILES "/home/dhruv-shah/ros_ws/rover_simulation/husky_test/src/husky_navigation/package.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/husky_navigation" TYPE DIRECTORY FILES
    "/home/dhruv-shah/ros_ws/rover_simulation/husky_test/src/husky_navigation/config"
    "/home/dhruv-shah/ros_ws/rover_simulation/husky_test/src/husky_navigation/launch"
    "/home/dhruv-shah/ros_ws/rover_simulation/husky_test/src/husky_navigation/maps"
    )
endif()

