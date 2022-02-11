cmake_minimum_required(VERSION 3.21)
project(task9)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(task9
        paginator.cpp
        test_runner.h)
