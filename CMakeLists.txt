Cmake_minimum_required(VERSION 3.8)
project(Primer VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Person)
add_subdirectory(SalesData)
add_subdirectory(ScreenWindow)
add_subdirectory(Chapter_7)
add_subdirectory(Debug)
add_subdirectory(Account)
add_subdirectory(Chapter_12)

add_executable(Primer  main.cpp)
target_link_libraries(Primer PUBLIC Person SalesData ScreenWindow Chapter_7 Debug Account Chapter_12)
target_include_directories(Primer PUBLIC
                       	  "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Person"
			  "${PROJECT_SOURCE_DIR}/SalesData"
			  "${PROJECT_SOURCE_DIR}/ScreenWindow"
			  "${PROJECT_SOURCE_DIR}/Chapter_7"
			  "${PROJECT_SOURCE_DIR}/Chapter_12"
			  "${PROJECT_SOURCE_DIR}/Debug"
			  "${PROJECT_SOURCE_DIR}/Account"
                          )