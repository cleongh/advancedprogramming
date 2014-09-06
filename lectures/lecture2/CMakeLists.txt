cmake_minimum_required (VERSION 2.6)

project (lecture2)

# remember to enable c++11!!!
add_definitions(-std=c++11)

add_executable(big_o big_o.cpp)
add_executable(ranged_for ranged_for.cpp)
add_executable(iterators iterators.cpp)
