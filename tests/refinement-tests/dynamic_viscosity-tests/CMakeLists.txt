message(STATUS "Building dynamic_viscosity test")

set(target dynamic_viscosity-refinement-test)
message(STATUS "Building library ${target}")

set(sources dynamic_viscosity-tests.cpp)

add_executable(${target} ${sources})
add_test(dynamic_viscosity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(dynamic_viscosity PROPERTIES LABELS "refinement")
