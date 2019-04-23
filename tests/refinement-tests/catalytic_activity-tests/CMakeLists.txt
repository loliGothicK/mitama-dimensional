message(STATUS "Building catalytic_activity test")

set(target catalytic_activity-refinement-test)
message(STATUS "Building library ${target}")

set(sources catalytic_activity-tests.cpp)

add_executable(${target} ${sources})
add_test(catalytic_activity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(catalytic_activity PROPERTIES LABELS "refinement")
