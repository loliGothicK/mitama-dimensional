message(STATUS "Building electric_displacement_field test")

set(target electric_displacement_field-refinement-test)
message(STATUS "Building library ${target}")

set(sources electric_displacement_field-tests.cpp)

add_executable(${target} ${sources})
add_test(electric_displacement_field "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(electric_displacement_field PROPERTIES LABELS "refinement")
