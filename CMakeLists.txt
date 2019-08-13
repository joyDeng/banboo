cmake_minimum_required (VERSION 2.6)
project (Banboo)

# The version number
set (Banboo_VERSION_MAJOR 1)
set (Banboo_VERSION_MINOR 0)

# Set the output folder
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# add the binary tree to the search path for include file
include_directories("${PROJECT_BINARY_DIR}/lib")

# add add_executable
add_executable(Banboo ${PROJECT_SOURCE_DIR}/main.cpp)



