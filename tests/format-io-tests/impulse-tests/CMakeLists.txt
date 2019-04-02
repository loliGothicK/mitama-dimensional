message(STATUS "Building impulse test")

set(target impulse-format-test)
message(STATUS "Building library ${target}")

set(sources impulse-tests.cpp)

add_executable(${target} ${sources})
add_test(impulse "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(impulse PROPERTIES LABELS "format")
