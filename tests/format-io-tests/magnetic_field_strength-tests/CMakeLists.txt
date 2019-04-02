message(STATUS "Building magnetic_field_strength test")

set(target magnetic_field_strength-format-test)
message(STATUS "Building library ${target}")

set(sources magnetic_field_strength-tests.cpp)

add_executable(${target} ${sources})
add_test(magnetic_field_strength "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(magnetic_field_strength PROPERTIES LABELS "format")
