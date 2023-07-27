project(Account)
file(GLOB Account_src "*.h" "*.cpp")
add_library(Account ${Account_src})