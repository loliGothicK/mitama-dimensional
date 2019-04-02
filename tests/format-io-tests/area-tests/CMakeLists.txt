message(STATUS "Building area test")

set(target area-format-test)
message(STATUS "Building library ${target}")

set(sources area-tests.cpp)

add_executable(${target} ${sources})
add_test(area "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(area PROPERTIES LABELS "format")
