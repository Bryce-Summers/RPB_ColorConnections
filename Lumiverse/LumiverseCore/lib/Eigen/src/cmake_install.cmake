# Install script for directory: C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src

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

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/Cholesky/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/CholmodSupport/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/Core/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/Eigen2Support/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/Eigenvalues/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/Geometry/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/Householder/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/IterativeLinearSolvers/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/Jacobi/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/LU/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/MetisSupport/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/misc/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/OrderingMethods/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/PardisoSupport/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/PaStiXSupport/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/plugins/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/QR/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/SparseCholesky/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/SparseCore/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/SparseLU/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/SparseQR/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/SPQRSupport/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/StlSupport/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/SuperLUSupport/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/SVD/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/UmfPackSupport/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

