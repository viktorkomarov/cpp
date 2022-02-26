cmake_minimum_required(VERSION 3.21)
project(task2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(task2
        swap.cpp
        test_runner.h)
