message(STATUS "Building momentum test")

set(target momentum-refinement-test)
message(STATUS "Building library ${target}")

set(sources momentum-tests.cpp)

add_executable(${target} ${sources})
add_test(momentum "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(momentum PROPERTIES LABELS "refinement")
