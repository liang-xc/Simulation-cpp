add_executable(european_option EuropeanOption.cpp ../../src/Forward.cpp ../../src/Forward.h ../../src/Date.cpp ../../src/Date.h)
target_link_libraries(european_option PRIVATE simu_lib)
