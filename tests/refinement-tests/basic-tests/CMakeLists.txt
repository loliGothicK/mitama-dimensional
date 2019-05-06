message(STATUS "Building basic test")

set(target basic-refinement-test)
message(STATUS "Building library ${target}")

set(sources basic-tests.cpp)

add_executable(${target} ${sources})
add_test(basic "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(basic PROPERTIES LABELS "refinement")
