Cmake_minimum_required(VERSION 3.8)
project(Exercises_section_12_2_1 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(Exercises_section_12_2_1 main.cpp 12.23.cpp 12.24.cpp interface.h)
target_include_directories(Exercises_section_12_2_1 PUBLIC
                       	  "${PROJECT_BINARY_DIR}"
                          )