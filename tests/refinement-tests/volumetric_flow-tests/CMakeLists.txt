message(STATUS "Building volumetric_flow test")

set(target volumetric_flow-refinement-test)
message(STATUS "Building library ${target}")

set(sources volumetric_flow-tests.cpp)

add_executable(${target} ${sources})
add_test(volumetric_flow "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(volumetric_flow PROPERTIES LABELS "refinement")
