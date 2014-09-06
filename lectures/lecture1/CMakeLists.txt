cmake_minimum_required (VERSION 2.6)

project (lecture1)

Find_Package ( SDL REQUIRED )



include_directories(${SDL_INCLUDE_DIR})

add_executable(example example.cpp)
add_executable(sdlexample sdlexample.cpp)

target_link_libraries(sdlexample ${SDL_LIBRARY})
