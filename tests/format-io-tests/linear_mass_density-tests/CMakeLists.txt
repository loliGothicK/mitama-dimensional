message(STATUS "Building linear_mass_density test")

set(target linear_mass_density-format-test)
message(STATUS "Building library ${target}")

set(sources linear_mass_density-tests.cpp)

add_executable(${target} ${sources})
add_test(linear_mass_density "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(linear_mass_density PROPERTIES LABELS "format")
