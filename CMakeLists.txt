cmake_minimum_required (VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" 
  CACHE STRING "Vcpkg toolchain file")
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project (Simulation-cpp)

set (source_dir "${PROJECT_SOURCE_DIR}/src")
file (GLOB source_files "${source_dir}/*.cpp")
add_executable (simulation ${source_files})

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++20")

find_package(Eigen3 CONFIG REQUIRED)
target_link_libraries(simulation PRIVATE Eigen3::Eigen)
