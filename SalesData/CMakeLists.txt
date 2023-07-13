project(SalesData)
file(GLOB SalesData_src "*.h" "*.cpp")
add_library(SalesData ${SalesData_src})