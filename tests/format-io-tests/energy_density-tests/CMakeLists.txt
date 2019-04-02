message(STATUS "Building energy_density test")

set(target energy_density-format-test)
message(STATUS "Building library ${target}")

set(sources energy_density-tests.cpp)

add_executable(${target} ${sources})
add_test(energy_density "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(energy_density PROPERTIES LABELS "format")
