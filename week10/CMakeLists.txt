cmake_minimum_required(VERSION 3.21)
project(week10)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(week10
        condition_parser.cpp
        condition_parser.h
        condition_parser_test.cpp
        main.cpp
        token.cpp
        token.h database.h node.h date.h test_runner.h date.cpp database.cpp node.cpp)
