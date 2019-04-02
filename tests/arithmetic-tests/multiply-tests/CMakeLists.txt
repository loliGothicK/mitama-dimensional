message(STATUS "Building multiply-value-check-tests test")

set(target multiply-value-check-tests-tests)
message(STATUS "Building library ${target}")

set(sources multiply-value-check-tests-tests.cpp)
add_executable(${target} ${sources})
add_test(multiply-value-check-tests "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(multiply-value-check-tests PROPERTIES LABELS "arithmetic")
