cmake_minimum_required(VERSION 3.20)
project(test)

set(CMAKE_CXX_STANDARD 17)

include_directories(../src ../../../googletest/googletest ../../../googletest/googletest/include ../../simple-str/src)

add_executable(test mainTest.cpp ../../../googletest/googletest/src/gtest-all.cc ../src/date.cpp ../../simple-str/src/simple-str.cpp)