# The user can pass a hint for the include directory and library location
set(GPDDATABASE_INSTALATION "" CACHE PATH "Hint for where gpddatabase might be located")

# Find the include directory
find_path(GPDDATABASE_INCLUDE_DIRS
    NAMES gpddatabase/ExclusiveDatabase.h
    PATHS ${CMAKE_CURRENT_LIST_DIR}/include /usr/local/include /usr/include
    HINTS ${GPDDATABASE_INSTALATION}/include
    PATH_SUFFIXES gpddatabase
)

# Find the library
find_library(GPDDATABASE_LIBRARIES
    NAMES gpddatabase
    PATHS ${CMAKE_CURRENT_LIST_DIR}/lib /usr/local/lib /usr/lib
    HINTS ${GPDDATABASE_INSTALATION}/lib
)

# Set GPDDATABASE_FOUND to true if both the include directory and library are found
if(GPDDATABASE_INCLUDE_DIRS AND GPDDATABASE_LIBRARIES)
    set(GPDDATABASE_FOUND TRUE)
else()
    set(GPDDATABASE_FOUND FALSE)
endif()

# Print status messages
if(GPDDATABASE_FOUND)
    message(STATUS "Found gpddatabase: ${GPDDATABASE_LIBRARIES}")
    message(STATUS "Include directory: ${GPDDATABASE_INCLUDE_DIRS}")
else()
    message(FATAL_ERROR "Could not find gpddatabase")
endif()

# Provide the include directories and libraries for consumers of this module
mark_as_advanced(GPDDATABASE_INCLUDE_DIRS GPDDATABASE_LIBRARIES)
