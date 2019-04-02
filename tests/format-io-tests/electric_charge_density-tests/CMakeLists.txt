message(STATUS "Building electric_charge_density test")

set(target electric_charge_density-format-test)
message(STATUS "Building library ${target}")

set(sources electric_charge_density-tests.cpp)

add_executable(${target} ${sources})
add_test(electric_charge_density "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(electric_charge_density PROPERTIES LABELS "format")
