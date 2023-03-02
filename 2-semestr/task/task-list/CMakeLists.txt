cmake_minimum_required(VERSION 3.21)
project(task-list)

set(CMAKE_CXX_STANDARD 17)

include_directories(../src)

add_executable(task-list main.cpp src/Book.cpp)