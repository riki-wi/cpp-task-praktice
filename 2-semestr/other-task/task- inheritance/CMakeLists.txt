cmake_minimum_required(VERSION 3.21)
project(task-inheritance)

set(CMAKE_CXX_STANDARD 17)

include_directories(../src)

add_executable(task-inheritance main.cpp src/TwoThree.cpp)