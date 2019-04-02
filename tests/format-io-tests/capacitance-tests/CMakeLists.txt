message(STATUS "Building capacitance test")

set(target capacitance-format-test)
message(STATUS "Building library ${target}")

set(sources capacitance-tests.cpp)

add_executable(${target} ${sources})
add_test(capacitance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(capacitance PROPERTIES LABELS "format")
