message(STATUS "Building weight test")

set(target weight-refinement-test)
message(STATUS "Building library ${target}")

set(sources weight-tests.cpp)

add_executable(${target} ${sources})
add_test(weight "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(weight PROPERTIES LABELS "refinement")
