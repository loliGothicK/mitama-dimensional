message(STATUS "Building acceleration test")

set(target acceleration-format-test)
message(STATUS "Building library ${target}")

set(sources acceleration-tests.cpp)

add_executable(${target} ${sources})
add_test(acceleration "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(acceleration PROPERTIES LABELS "format")
