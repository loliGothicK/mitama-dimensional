message(STATUS "Building entropy test")

set(target entropy-format-test)
message(STATUS "Building library ${target}")

set(sources entropy-tests.cpp)

add_executable(${target} ${sources})
add_test(entropy "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(entropy PROPERTIES LABELS "format")
