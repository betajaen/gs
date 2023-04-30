cmake_minimum_required(VERSION 3.24)
project(gs)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(gs
        source/main.cpp)


target_include_directories(gs PUBLIC
        source/include
        )

set_target_properties(gs
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/progdir"
        )