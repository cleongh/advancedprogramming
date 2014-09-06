cmake_minimum_required (VERSION 2.6)

project (lecture3)

# remember to enable c++11!!!
add_definitions(-std=c++11)

add_executable(rvalues_lvalues rvalues_lvalues.cpp)
add_executable(raii raii.cpp)
add_executable(raii_exceptions raii_exceptions.cpp)
