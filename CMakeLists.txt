# CMakeList.txt : CMake project for cajlib, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("cajlib")

include_directories(include)

#Sources
set (SOURCES 
	"${CMAKE_CURRENT_SOURCE_DIR}/src/conversion/conversion.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/string/string.cpp"
)

set (HEADERS
	"${CMAKE_CURRENT_SOURCE_DIR}/include/cajlib.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/conversion/conversion.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/string/string.h"
)

# Add source to this project's executable.
add_library (cajlib STATIC ${SOURCES} ${HEADERS})
add_executable(testcajlib "testcajlib.cpp")
target_link_libraries(testcajlib PRIVATE cajlib)

# TODO: Add tests and install targets if needed.
enable_testing()

add_test(NAME works COMMAND testcajlib)
set_tests_properties(works
  PROPERTIES PASS_REGULAR_EXPRESSION "works..."
  )

function(do_test target test_name arg result)	
	add_test(NAME ${test_name} COMMAND testcajlib ${test_name} ${arg})
	set_tests_properties(
		${test_name}
		PROPERTIES PASS_REGULAR_EXPRESSION ${result}
	 )
endfunction()

do_test(testcajlib "stringToInt" "192" "result: 192")
do_test(testcajlib "intToString" "100321" "result: 100321")
do_test(testcajlib "addChar" "yo" "result: yolo")
do_test(testcajlib "decimalToBinary" "543765" "result: 1000 0100 1100 0001 0101")