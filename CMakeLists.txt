cmake_minimum_required (VERSION 2.8.11)
project (Banboo)

add_library(stb INTERFACE)

target_include_directories(stb INTERFACE ${Banboo_SOURCE_DIR}/include/)

add_executable (writeImage
 # header
 include/vector.h
 include/ray.h
 # source file
 src/vector.cpp
 banboo.cpp
 )

target_link_libraries (writeImage LINK_PUBLIC stb)