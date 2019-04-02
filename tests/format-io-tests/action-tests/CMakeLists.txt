message(STATUS "Building action test")

set(target action-format-test)
message(STATUS "Building library ${target}")

set(sources action-tests.cpp)

add_executable(${target} ${sources})
add_test(action "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(action PROPERTIES LABELS "format")
