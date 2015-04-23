cmake_minimum_required (VERSION 2.6)

project (RPB_SHOW)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake/modules")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /home/s15_group4/Desktop/modules/)


# defaulting to release build
IF (NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "Release" CACHE STRING "Type of build (Debug Release RelWithDebInfo MinSizeRel)" FORCE)
ENDIF ()



# Compiler options
IF(APPLE)
    SET(CLANG_FLAGS "-std=c++11 -stdlib=libc++")
    
    # HACK(kayvonf): removing frequently occurring warnings due to clp
    # sloppiness.  If possible, someone should try to surpress these
    # warnings only for the relevant file(s).
    SET(CLANG_FLAGS "${CLANG_FLAGS} -Wno-deprecated-register -Wno-extra-tokens")
    
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CLANG_FLAGS}")
ELSEIF(UNIX OR LINUX)
    SET(GCC_FLAGS "-std=c++11 -pthread -fPIC")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_FLAGS}")
    MESSAGE("Detected platform Unix: Adding -std=c++11 to g++ flags")
ENDIF(APPLE)

# Set source files
set (SERVER_SOURCE
  main.cpp src/BridgeInterface.cpp src/BridgeModel.cpp
  src/Color.cpp
  src/ColorPanel.cpp
  src/MainLoop.cpp
  src/TravelingColor.cpp
)


find_package(Lumiverse REQUIRED)
include_directories(${LUMIVERSE_INCLUDE_DIR})
include_directories(/home/s15_group4/Desktop/RPB_ColorConnections/src)
include_directories(/home/s15_group4/Desktop/RPB_ColorConnections/include)
set(ACTIVE_LIBRARIES ${LUMIVERSE_LIBRARIES})

add_executable (RPB_4 ${SERVER_SOURCE})
target_link_libraries(RPB_4 ${ACTIVE_LIBRARIES})
