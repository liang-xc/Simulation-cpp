cmake_minimum_required (VERSION 3.15)

project (Simulation-cpp)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++20")
set (source_dir "${PROJECT_SOURCE_DIR}/src")

file (GLOB source_files "${source_dir}/*.cpp")

add_executable (simulation ${source_files})
