cmake_minimum_required (VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project (Simulation-cpp)

set (source_dir "${PROJECT_SOURCE_DIR}/src")
file (GLOB source_files "${source_dir}/*.cpp")
add_executable (simulation ${source_files})

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++20")
