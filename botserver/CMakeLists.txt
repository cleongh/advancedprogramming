cmake_minimum_required (VERSION 2.6) 
project (botserver)

find_package(Boost 1.40.0 REQUIRED COMPONENTS system thread serialization program_options)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")

add_definitions(-std=c++11)

include_directories(${Boost_INCLUDE_DIR})

include_directories(../bots)

link_directories( ${link_directories} ../bots ) 

add_executable(botserver main.cpp)

target_link_libraries(botserver bots)
target_link_libraries(botserver pthread)
target_link_libraries(botserver ${Boost_LIBRARIES})
target_link_libraries(botserver  ${Boost_THREAD_LIBRARY})
target_link_libraries(botserver ${Boost_PROGRAM_OPTIONS_LIBRARY})

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
