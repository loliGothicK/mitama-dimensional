message(STATUS "Building electric_field_strength test")

set(target electric_field_strength-refinement-test)
message(STATUS "Building library ${target}")

set(sources electric_field_strength-tests.cpp)

add_executable(${target} ${sources})
add_test(electric_field_strength "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(electric_field_strength PROPERTIES LABELS "refinement")
