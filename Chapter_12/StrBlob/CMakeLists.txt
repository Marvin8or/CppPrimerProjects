project(StrBlob)
file(GLOB StrBlob_src "*.h" "*.cpp")
add_library(StrBlob ${StrBlob_src})