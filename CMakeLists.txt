# CMakeList.txt : CMake project for cajlib, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("cajlib")

include_directories(include)

#Sources
set (SOURCES 
	"${CMAKE_SOURCE_DIR}/src/cajlib.cpp"
	"${CMAKE_SOURCE_DIR}/src/conversion/conversion.cpp"
)

set (HEADERS
	"${CMAKE_SOURCE_DIR}/include/cajlib.h"
	"${CMAKE_SOURCE_DIR}/include/conversion/conversion.h"
)

# Add source to this project's executable.
add_library (cajlib STATIC ${SOURCES} ${HEADERS})
add_executable(testcajlib "testcajlib.cpp")
target_link_libraries(testcajlib PRIVATE cajlib)

# TODO: Add tests and install targets if needed.
