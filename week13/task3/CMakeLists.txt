cmake_minimum_required(VERSION 3.21)
project(task3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(task3
        simple_vector.cpp
        simple_vector.h
        test_runner.h)
