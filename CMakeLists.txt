cmake_minimum_required (VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" 
  CACHE STRING "Vcpkg toolchain file")
set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++20")

project (Simulation-cpp)
add_subdirectory(src)
add_subdirectory(examples)
