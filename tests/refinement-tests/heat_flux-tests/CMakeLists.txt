message(STATUS "Building heat_flux test")

set(target heat_flux-refinement-test)
message(STATUS "Building library ${target}")

set(sources heat_flux-tests.cpp)

add_executable(${target} ${sources})
add_test(heat_flux "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(heat_flux PROPERTIES LABELS "refinement")
