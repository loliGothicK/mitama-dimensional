message(STATUS "Building specific_heat_capacity test")

set(target specific_heat_capacity-refinement-test)
message(STATUS "Building library ${target}")

set(sources specific_heat_capacity-tests.cpp)

add_executable(${target} ${sources})
add_test(specific_heat_capacity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(specific_heat_capacity PROPERTIES LABELS "refinement")
