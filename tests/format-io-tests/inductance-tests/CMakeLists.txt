message(STATUS "Building inductance test")

set(target inductance-format-test)
message(STATUS "Building library ${target}")

set(sources inductance-tests.cpp)

add_executable(${target} ${sources})
add_test(inductance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(inductance PROPERTIES LABELS "format")
