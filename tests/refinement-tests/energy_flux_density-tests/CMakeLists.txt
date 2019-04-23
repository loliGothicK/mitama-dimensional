message(STATUS "Building energy_flux_density test")

set(target energy_flux_density-refinement-test)
message(STATUS "Building library ${target}")

set(sources energy_flux_density-tests.cpp)

add_executable(${target} ${sources})
add_test(energy_flux_density "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(energy_flux_density PROPERTIES LABELS "refinement")
