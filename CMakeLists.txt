# CMakeList.txt : CMake project for cajlib, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("cajlib")

include_directories(include)
# Add source to this project's executable.
add_library (cajlib STATIC "cajlib.cpp" "include/cajlib.h")
add_executable(testcajlib "testcajlib.cpp")
target_link_libraries(testcajlib cajlib)

# TODO: Add tests and install targets if needed.
