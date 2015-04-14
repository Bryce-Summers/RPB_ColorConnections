# Install script for directory: C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support

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

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lib/Eigen/src/Eigen2Support" TYPE FILE FILES
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/Block.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/Cwise.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/CwiseOperators.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/Lazy.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/LeastSquares.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/LU.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/Macros.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/MathFunctions.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/Memory.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/Meta.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/Minor.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/QR.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/SVD.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/TriangularSolver.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Eigen2Support/VectorBlock.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/Eigen2Support/Geometry/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

