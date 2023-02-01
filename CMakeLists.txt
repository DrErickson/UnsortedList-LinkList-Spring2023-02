cmake_minimum_required(VERSION 3.17)
project(unsortedlist)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(unsortedlist
        TestDriver.cpp
        UnsortedList.h)
