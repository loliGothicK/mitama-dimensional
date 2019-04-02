message(STATUS "Building linear_charge_density test")

set(target linear_charge_density-format-test)
message(STATUS "Building library ${target}")

set(sources linear_charge_density-tests.cpp)

add_executable(${target} ${sources})
add_test(linear_charge_density "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(linear_charge_density PROPERTIES LABELS "format")
