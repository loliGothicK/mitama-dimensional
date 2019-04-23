message(STATUS "Building angular_acceleration test")

set(target angular_acceleration-refinement-test)
message(STATUS "Building library ${target}")

set(sources angular_acceleration-tests.cpp)

add_executable(${target} ${sources})
add_test(angular_acceleration "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(angular_acceleration PROPERTIES LABELS "refinement")
