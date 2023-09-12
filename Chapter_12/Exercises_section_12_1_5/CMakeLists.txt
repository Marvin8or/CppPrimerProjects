Cmake_minimum_required(VERSION 3.8)
project(Exercises_section_12_1_5 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(Exercises_section_12_1_5 main.cpp)
target_include_directories(Exercises_section_12_1_5 PUBLIC
                       	  "${PROJECT_BINARY_DIR}"
                          )