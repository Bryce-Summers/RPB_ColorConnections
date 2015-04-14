# Install script for directory: C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseShowControl

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Lumiverse")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/LumiverseShowControl" TYPE FILE FILES
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseShowControl/Cue.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseShowControl/CueList.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseShowControl/Keyframe.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseShowControl/Layer.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseShowControl/LumiverseShowControl.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseShowControl/Playback.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseShowControl/Programmer.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseShowControl/SineWave.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseShowControl/Snapshot.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseShowControl/Timeline.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseShowControl/libLumiverseShowControl.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

