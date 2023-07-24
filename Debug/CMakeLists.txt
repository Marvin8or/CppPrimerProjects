project(Debug)
file(GLOB Debug_src "*.h" "*.cpp")
add_library(Debug ${Debug_src})