message(STATUS "Building kinematic_viscosity test")

set(target kinematic_viscosity-refinement-test)
message(STATUS "Building library ${target}")

set(sources kinematic_viscosity-tests.cpp)

add_executable(${target} ${sources})
add_test(kinematic_viscosity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(kinematic_viscosity PROPERTIES LABELS "refinement")
