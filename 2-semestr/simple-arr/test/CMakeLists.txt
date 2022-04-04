cmake_minimum_required(VERSION 3.20)
project(test)

set(CMAKE_CXX_STANDARD 17)

include_directories(src /Users/polzovatel/Documents/googletest-main/googletest/include
        /Users/polzovatel/Documents/googletest-main/googletest)

add_executable(test googleTest/gtest-all.cc ArrTest.cpp)