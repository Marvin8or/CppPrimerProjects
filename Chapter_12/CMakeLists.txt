Cmake_minimum_required(VERSION 3.8)
project(Chapter_12 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory(Exercises_section_12_1_2)

add_executable(Chapter_12  main.cpp)
target_link_libraries(Chapter_12 PUBLIC Exercises_section_12_1_2)
target_include_directories(Chapter_12 PUBLIC
                       	  "${PROJECT_BINARY_DIR}"
			  "${PROJECT_SOURCE_DIR}/Person/Exercises_section_12_1_2"
                          )