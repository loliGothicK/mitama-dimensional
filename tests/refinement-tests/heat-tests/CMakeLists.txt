message(STATUS "Building heat test")

set(target heat-refinement-test)
message(STATUS "Building library ${target}")

set(sources heat-tests.cpp)

add_executable(${target} ${sources})
add_test(heat "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(heat PROPERTIES LABELS "refinement")
