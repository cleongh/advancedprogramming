cmake_minimum_required (VERSION 2.6)

project (lecture4)

# remember to enable c++11!!!
add_definitions(-std=c++11)

add_executable(const const.cpp)
add_executable(namespaces namespaces.cpp)
add_executable(unicode unicode.cpp)
add_executable(static static.cpp static_header.cpp)

