cmake_minimum_required(VERSION 3.24)
project(gs)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(gs
        source/hw/entry.cpp
        source/util/debug.cpp
        source/util/string.cpp)


target_include_directories(gs PUBLIC
        include
        )

target_compile_options(gs PUBLIC
        -ldebug
        -noixemul
        -nostdlib
        -fno-exceptions
        -fno-rtti
        -fno-threadsafe-statics
        -m68020
        )

target_compile_definitions(gs PUBLIC
        gs_version="2.0.0"
)

set_target_properties(gs
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/progdir"
        )