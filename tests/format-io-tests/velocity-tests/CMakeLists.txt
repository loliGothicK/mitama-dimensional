message(STATUS "Building velocity test")

set(target velocity-format-test)
message(STATUS "Building library ${target}")

set(sources velocity-tests.cpp)

add_executable(${target} ${sources})
add_test(velocity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(velocity PROPERTIES LABELS "format")
