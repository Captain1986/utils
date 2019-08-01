cmake_minimum_required(VERSION 2.8)
project(ADD)

set(CMAKE_BUILD_TYPE Release)

# 指定安装路径
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install" CACHE PATH "Installation Directory")
endif()

message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")

if(${CMAKE_MAJOR_VERSION} GREATER 2)
   CMAKE_POLICY(SET CMP0026 OLD)
endif()

# VERBOSE开关
set(CMAKE_VERBOSE_MAKEFILE ON)
# 打印平台信息
message(STATUS "Operation System: " ${CMAKE_SYSTEM})

# 设置编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror -Wall -fvisibility=hidden -fPIC -O3")
# 设置链接选项
set(CMAKE_LDFLAGS "${CMAKE_LDFLAGS} -Wl,--gc-sections")

#add cuda
#set(CUDA_DIR /usr/local/cuda-9.0)
#find_package(CUDA REQUIRED)
#include_directories(${CUDA_DIR}/include)
#link_directories(${CUDA_DIR}/lib64)

#add opencv
#set(OpenCV_DIR /home/dup/Downloads/opencv-3.4.1/build/install/share/OpenCV)
#find_package(OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})
#link_directories(${OpenCV_LIBRARIES_DIRS})
#message(STATUS "OpenCV libraries: " ${OpenCV_LIBS})

#set rpath
#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
#set(CMAKE_INSTALL_RPATH ./lib ./lib/tensorRT ./build)
#set(CMAKE_BUILD_WITH_INSTALL_RPATH true)

add_subdirectory(src/)
add_subdirectory(sample/)
