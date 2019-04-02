message(STATUS "Building illuminance test")

set(target illuminance-format-test)
message(STATUS "Building library ${target}")

set(sources illuminance-tests.cpp)

add_executable(${target} ${sources})
add_test(illuminance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(illuminance PROPERTIES LABELS "format")
