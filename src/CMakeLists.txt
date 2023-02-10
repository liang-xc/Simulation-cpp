file(GLOB simu_src "*.cpp")
add_library(simu_lib ${simu_src})
target_link_libraries(simu_lib PRIVATE Eigen3::Eigen)
target_include_directories(simu_lib PUBLIC .)
