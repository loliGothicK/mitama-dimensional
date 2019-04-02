message(STATUS "Building volume test")

set(target volume-format-test)
message(STATUS "Building library ${target}")

set(sources volume-tests.cpp)

add_executable(${target} ${sources})
add_test(volume "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(volume PROPERTIES LABELS "format")
