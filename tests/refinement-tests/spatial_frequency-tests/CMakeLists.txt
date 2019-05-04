message(STATUS "Building spatial_frequency test")

set(target spatial_frequency-refinement-test)
message(STATUS "Building library ${target}")

set(sources spatial_frequency-tests.cpp)

add_executable(${target} ${sources})
add_test(spatial_frequency "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(spatial_frequency PROPERTIES LABELS "refinement")
