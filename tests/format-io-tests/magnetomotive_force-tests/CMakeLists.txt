message(STATUS "Building magnetomotive_force test")

set(target magnetomotive_force-format-test)
message(STATUS "Building library ${target}")

set(sources magnetomotive_force-tests.cpp)

add_executable(${target} ${sources})
add_test(magnetomotive_force "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(magnetomotive_force PROPERTIES LABELS "format")
