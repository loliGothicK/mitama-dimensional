message(STATUS "Building thermal_diffusivity test")

set(target thermal_diffusivity-refinement-test)
message(STATUS "Building library ${target}")

set(sources thermal_diffusivity-tests.cpp)

add_executable(${target} ${sources})
add_test(thermal_diffusivity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(thermal_diffusivity PROPERTIES LABELS "refinement")
