message(STATUS "Building division test")

set(target division-tests)
message(STATUS "Building library ${target}")

set(sources division-tests.cpp)
add_executable(${target} ${sources})
add_test(division-tests "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(division-tests PROPERTIES LABELS "arithmetic")
