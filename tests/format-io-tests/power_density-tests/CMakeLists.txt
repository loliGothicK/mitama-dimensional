message(STATUS "Building power_density test")

set(target power_density-format-test)
message(STATUS "Building library ${target}")

set(sources power_density-tests.cpp)

add_executable(${target} ${sources})
add_test(power_density "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(power_density PROPERTIES LABELS "format")
