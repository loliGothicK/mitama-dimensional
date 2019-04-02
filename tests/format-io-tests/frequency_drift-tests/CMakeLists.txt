message(STATUS "Building frequency_drift test")

set(target frequency_drift-format-test)
message(STATUS "Building library ${target}")

set(sources frequency_drift-tests.cpp)

add_executable(${target} ${sources})
add_test(frequency_drift "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(frequency_drift PROPERTIES LABELS "format")
