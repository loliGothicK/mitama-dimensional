message(STATUS "Building electoric_potential test")

set(target electoric_potential-format-test)
message(STATUS "Building library ${target}")

set(sources electoric_potential-tests.cpp)

add_executable(${target} ${sources})
add_test(algorithm "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(algorithm PROPERTIES LABELS "format")
