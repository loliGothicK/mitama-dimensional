message(STATUS "Building magnetic_flux_density test")

set(target magnetic_flux_density-format-test)
message(STATUS "Building library ${target}")

set(sources magnetic_flux_density-tests.cpp)

add_executable(${target} ${sources})
add_test(magnetic_flux_density "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(magnetic_flux_density PROPERTIES LABELS "format")
