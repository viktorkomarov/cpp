cmake_minimum_required(VERSION 3.21)
project(task4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(task4
        stack_vector.cpp
        stack_vector.h)
