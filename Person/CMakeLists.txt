Cmake_minimum_required(VERSION 3.8)
project(Person VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Person main.cpp Person.cpp Person.h Sales_data.cpp Sales_data.h)
