Cmake_minimum_required(VERSION 3.8)
project(TextQuery VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(TextQuery main.cpp TextQuery.cpp TextQuery.h QueryResult.cpp QueryResult.h)
target_include_directories(TextQuery PUBLIC
                       	  "${PROJECT_BINARY_DIR}"
                          )