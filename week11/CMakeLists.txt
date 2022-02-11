cmake_minimum_required(VERSION 3.21)
project(week11)

set(CMAKE_CXX_STANDARD 14)

include_directories(task1)
include_directories(task2)
include_directories(task3)
include_directories(task4)
include_directories(task7)

add_executable(week11
        task1/main.cpp
        task1/max_element_if.cpp
        task1/test_runner.h
        task2/log.cpp
        task2/test_runner.h
        task3/airline_ticket.h
        task3/sort_by.cpp
        task3/test_runner.h
        task4/airline_ticket.h
        task4/test_runner.h
        task4/update_field.cpp
        task5/bad_macro.cpp
        task6/uniq_id.cpp
        task7/table.cpp
        task7/test_runner.h)
