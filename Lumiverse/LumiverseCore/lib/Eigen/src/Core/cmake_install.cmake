# Install script for directory: C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lib/Eigen/src/Core" TYPE FILE FILES
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Array.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/ArrayBase.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/ArrayWrapper.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Assign.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Assign_MKL.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/BandMatrix.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Block.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/BooleanRedux.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/CommaInitializer.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/CoreIterators.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/CwiseBinaryOp.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/CwiseNullaryOp.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/CwiseUnaryOp.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/CwiseUnaryView.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/DenseBase.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/DenseCoeffsBase.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/DenseStorage.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Diagonal.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/DiagonalMatrix.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/DiagonalProduct.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Dot.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/EigenBase.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Flagged.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/ForceAlignedAccess.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Functors.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Fuzzy.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/GeneralProduct.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/GenericPacketMath.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/GlobalFunctions.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/IO.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Map.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/MapBase.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/MathFunctions.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Matrix.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/MatrixBase.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/NestByValue.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/NoAlias.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/NumTraits.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/PermutationMatrix.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/PlainObjectBase.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/ProductBase.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Random.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Redux.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Ref.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Replicate.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/ReturnByValue.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Reverse.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Select.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/SelfAdjointView.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/SelfCwiseBinaryOp.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/SolveTriangular.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/StableNorm.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Stride.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Swap.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Transpose.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Transpositions.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/TriangularMatrix.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/VectorBlock.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/VectorwiseOp.h"
    "C:/Users/Bryce/Desktop/GIT CODE/Lumiverse/Lumiverse/source/LumiverseCore/lib/Eigen/src/Core/Visitor.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/Core/products/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/Core/util/cmake_install.cmake")
  INCLUDE("C:/Users/Bryce/Desktop/GIT CODE/RPB_ColorConnections/Lumiverse/LumiverseCore/lib/Eigen/src/Core/arch/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

