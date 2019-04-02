message(STATUS "Building division-value-check-tests-value-check-tests test")

set(target division-value-check-tests-value-check-tests-tests)
message(STATUS "Building library ${target}")

set(sources division-value-check-tests-value-check-tests-tests.cpp)
add_executable(${target} ${sources})
add_test(division-value-check-tests-value-check-tests "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(division-value-check-tests-value-check-tests PROPERTIES LABELS "arithmetic")
