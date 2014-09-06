cmake_minimum_required (VERSION 2.6)

project (bots)

add_definitions(-std=c++11)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")

find_package(Boost 1.40.0 REQUIRED COMPONENTS serialization)

include_directories(${BOOST_INCLUDE_DIR})

add_library(bots bot.cpp bots.cpp)

FIND_PACKAGE(Doxygen)
if (NOT DOXYGEN_FOUND)
    message(FATAL_ERROR 
      "Doxygen is needed to build the documentation. Please install it correctly")
  endif()

  configure_file(Doxyfile
                 ${PROJECT_BINARY_DIR}/Doxyfile  @ONLY IMMEDIATE)
  add_custom_target (Docs ALL 
                                          COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/Doxyfile
                                          SOURCES ${PROJECT_BINARY_DIR}/Doxyfile)

