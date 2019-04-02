message(STATUS "Building frequency test")

set(target frequency-format-test)
message(STATUS "Building library ${target}")

set(sources frequency-tests.cpp)

add_executable(${target} ${sources})
add_test(frequency "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(frequency PROPERTIES LABELS "format")
