cmake_minimum_required(VERSION 3.24)
project(gs)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

set(gs_common_src
        source/hw/entry.cpp
        source/util/debug.cpp
        source/util/string.cpp
        source/util/memory.cpp
        source/common/configuration.cpp)

set(gs_common_compile_options
        -ldebug
        -noixemul
        -nostdlib
        -fno-exceptions
        -fno-rtti
        -fno-threadsafe-statics
        -m68020)

set(gs_common_include include)

add_compile_definitions(
        gs_version="2.0.0"
        gs_debug_memory=1
)

# ------------------------------------------

add_executable(gs
        source/game/main.cpp
        ${gs_common_src}
)

target_include_directories(gs PUBLIC ${gs_common_include})
set_target_properties(gs PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/progdir")

# ------------------------------------------

add_executable(gs_convert_data
        source/tools/convert_data/main.cpp
        ${gs_common_src}
)

target_include_directories(gs_convert_data PUBLIC ${gs_common_include})
set_target_properties(gs_convert_data PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/progdir")

# ------------------------------------------