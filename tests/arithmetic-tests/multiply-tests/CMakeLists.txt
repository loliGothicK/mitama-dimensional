message(STATUS "Building multiply test")

set(target multiply-value-check-tests-tests)
message(STATUS "Building library ${target}")

set(sources multiply-tests.cpp)
add_executable(${target} ${sources})
add_test(multiply-tests "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(multiply-tests PROPERTIES LABELS "arithmetic")
