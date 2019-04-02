message(STATUS "Building electric_charge test")

set(target electric_charge-format-test)
message(STATUS "Building library ${target}")

set(sources electric_charge-tests.cpp)

add_executable(${target} ${sources})
add_test(electric_charge "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(electric_charge PROPERTIES LABELS "format")
