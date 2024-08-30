# minimum version of cmake
cmake_minimum_required(VERSION 3.10)

# project name
project(gpddatabase CXX)

# set cpp standard
set(CMAKE_CXX_STANDARD 17)

# add compilator options
add_compile_options()

# add more modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

# find python
find_package(Python3 COMPONENTS Development REQUIRED)

# find gpddatabase
find_package(gpddatabase REQUIRED)

# includes
include_directories("${PROJECT_SOURCE_DIR}/include" ${Python3_INCLUDE_DIRS} ${GPDDATABASE_INCLUDE_DIRS})

# src
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# executable
add_executable(gpddatabase ${SOURCES})
set_target_properties(gpddatabase PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
target_link_libraries(gpddatabase PRIVATE ${Python3_LIBRARIES} ${GPDDATABASE_LIBRARIES} )
