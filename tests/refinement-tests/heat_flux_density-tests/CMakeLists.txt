message(STATUS "Building heat_flux_density test")

set(target heat_flux_density-refinement-test)
message(STATUS "Building library ${target}")

set(sources heat_flux_density-tests.cpp)

add_executable(${target} ${sources})
add_test(heat_flux_density "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(heat_flux_density PROPERTIES LABELS "refinement")
