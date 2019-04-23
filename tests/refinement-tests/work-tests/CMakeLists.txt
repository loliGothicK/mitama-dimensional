message(STATUS "Building work test")

set(target work-refinement-test)
message(STATUS "Building library ${target}")

set(sources work-tests.cpp)

add_executable(${target} ${sources})
add_test(work "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(work PROPERTIES LABELS "refinement")
