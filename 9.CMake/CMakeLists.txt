cmake_minimum_required(VERSION 2.8)

# 指定安装路径
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install" CACHE PATH "Installation Directory")
endif()

project(ADD)

message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")

if(${CMAKE_MAJOR_VERSION} GREATER 2)
   CMAKE_POLICY(SET CMP0026 OLD)
endif()

# VERBOSE开关
set(CMAKE_VERBOSE_MAKEFILE ON)
# 打印平台信息
message(STATUS "Operation System: " ${CMAKE_SYSTEM})

add_subdirectory(src/)
add_subdirectory(sample/)
