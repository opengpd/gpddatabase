# minimum version of cmake
cmake_minimum_required(VERSION 3.10)

# project name
project(gpddatabase CXX)

# set cpp standard
set(CMAKE_CXX_STANDARD 17)

# add compilator options
add_compile_options()

# find python
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# find numpy
execute_process(
	COMMAND "${Python3_EXECUTABLE}"
	-c "import numpy; print(numpy.get_include())"
	OUTPUT_VARIABLE NUMPY_INCLUDE_DIR
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

if(NOT DEFINED NUMPY_INCLUDE_DIR OR NUMPY_INCLUDE_DIR STREQUAL "")
    message(WARNING "Unable to find NumPy, which may result in a failed compilation")
else()
	message(STATUS "Found NumPy: " ${NUMPY_INCLUDE_DIR})
endif()

# includes
include_directories("${PROJECT_SOURCE_DIR}/include" ${Python3_INCLUDE_DIRS} ${NUMPY_INCLUDE_DIR})

# src
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# library
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_library(
	gpddatabase
	SHARED
	${SOURCES}
)

# define libraries to be linked
target_link_libraries(
	gpddatabase
	${Python3_LIBRARIES}
)

#install
install(TARGETS gpddatabase 
	LIBRARY DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include)
