cmake_minimum_required(VERSION 3.21)
project(task-polymorphism)

set(CMAKE_CXX_STANDARD 17)

include_directories(../src)

add_executable(polymorphism main.cpp src/Payment.cpp)