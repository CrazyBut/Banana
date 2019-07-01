cmake_minimum_required(VERSION 3.6)
project(OPZ_FROM_JAVA)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)
include_directories(googletest/googletest/include)
add_executable(opz main.cpp opz.h opz.cpp)
add_executable(tests Tests.cpp opz.h opz.cpp)
target_link_libraries(tests gtest gtest_main)