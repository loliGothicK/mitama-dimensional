message(STATUS "Building specific_volume test")

set(target specific_volume-format-test)
message(STATUS "Building library ${target}")

set(sources specific_volume-tests.cpp)

add_executable(${target} ${sources})
add_test(specific_volume "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(specific_volume PROPERTIES LABELS "format")
