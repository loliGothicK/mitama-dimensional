message(STATUS "Building temperature_gradient test")

set(target temperature_gradient-format-test)
message(STATUS "Building library ${target}")

set(sources temperature_gradient-tests.cpp)

add_executable(${target} ${sources})
add_test(temperature_gradient "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(temperature_gradient PROPERTIES LABELS "format")
