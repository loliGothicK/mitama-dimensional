message(STATUS "Building voltage test")

set(target voltage-format-test)
message(STATUS "Building library ${target}")

set(sources voltage-tests.cpp)

add_executable(${target} ${sources})
add_test(voltage "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(voltage PROPERTIES LABELS "format")
