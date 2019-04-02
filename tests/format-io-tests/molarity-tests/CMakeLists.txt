message(STATUS "Building molarity test")

set(target molarity-format-test)
message(STATUS "Building library ${target}")

set(sources molarity-tests.cpp)

add_executable(${target} ${sources})
add_test(molarity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(molarity PROPERTIES LABELS "format")
