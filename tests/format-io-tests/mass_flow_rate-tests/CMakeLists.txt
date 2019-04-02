message(STATUS "Building mass_flow_rate test")

set(target mass_flow_rate-format-test)
message(STATUS "Building library ${target}")

set(sources mass_flow_rate-tests.cpp)

add_executable(${target} ${sources})
add_test(mass_flow_rate "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(mass_flow_rate PROPERTIES LABELS "format")
