message(STATUS "Building molality test")

set(target molality-refinement-test)
message(STATUS "Building library ${target}")

set(sources molality-tests.cpp)

add_executable(${target} ${sources})
add_test(molality "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(molality PROPERTIES LABELS "refinement")
