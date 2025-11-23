cmake_minimum_required(VERSION 3.14)
project(my-vector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)

#add_library(vector STATIC
#	include/vector.hpp
#)

#target_include_directories(vector PUBLIC include)
include_directories(include)
add_executable(prog
	src/main.cpp
)

#target_link_libraries(prog PRIVATE vector)


