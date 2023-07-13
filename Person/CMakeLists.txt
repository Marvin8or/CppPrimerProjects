project(Person)
file(GLOB Person_src "*.h" "*.cpp")
add_library(Person ${Person_src})