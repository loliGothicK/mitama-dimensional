message(STATUS "Building addition-value-check-tests test")

set(target addition-value-check-tests)
message(STATUS "Building library ${target}")

set(sources addition-value-check-tests.cpp)
add_executable(${target} ${sources})
add_test(addition-value-check-tests "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(addition-value-check-tests PROPERTIES LABELS "arithmetic")
