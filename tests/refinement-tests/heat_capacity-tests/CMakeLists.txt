message(STATUS "Building heat_capacity test")

set(target heat_capacity-refinement-test)
message(STATUS "Building library ${target}")

set(sources heat_capacity-tests.cpp)

add_executable(${target} ${sources})
add_test(heat_capacity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(heat_capacity PROPERTIES LABELS "refinement")
