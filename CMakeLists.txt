Cmake_minimum_required(VERSION 3.8)
project(Primer VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Person)
add_subdirectory(SalesData)
add_subdirectory(ScreenWindow)

add_executable(Primer  main.cpp)
target_link_libraries(Primer PUBLIC Person SalesData ScreenWindow)
target_include_directories(Primer PUBLIC
                       	  "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Person"
			  "${PROJECT_SOURCE_DIR}/SalesData"
			  "${PROJECT_SOURCE_DIR}/ScreenWindow"
                          )