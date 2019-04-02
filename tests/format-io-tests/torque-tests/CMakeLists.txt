message(STATUS "Building torque test")

set(target torque-format-test)
message(STATUS "Building library ${target}")

set(sources torque-tests.cpp)

add_executable(${target} ${sources})
add_test(torque "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(torque PROPERTIES LABELS "format")
