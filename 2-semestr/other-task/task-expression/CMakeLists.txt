cmake_minimum_required(VERSION 3.21)
project(task-expression)

set(CMAKE_CXX_STANDARD 17)

include_directories(../src)

add_executable(task-expression main.cpp src/Expression.cpp)