message(STATUS "Building thermal_resistance test")

set(target thermal_resistance-format-test)
message(STATUS "Building library ${target}")

set(sources thermal_resistance-tests.cpp)

add_executable(${target} ${sources})
add_test(thermal_resistance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(thermal_resistance PROPERTIES LABELS "format")
