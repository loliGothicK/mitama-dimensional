message(STATUS "Building angular_velocity test")

set(target angular_velocity-format-test)
message(STATUS "Building library ${target}")

set(sources angular_velocity-tests.cpp)

add_executable(${target} ${sources})
add_test(angular_velocity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(angular_velocity PROPERTIES LABELS "format")
