message(STATUS "Building optical_power test")

set(target optical_power-refinement-test)
message(STATUS "Building library ${target}")

set(sources optical_power-tests.cpp)

add_executable(${target} ${sources})
add_test(optical_power "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(optical_power PROPERTIES LABELS "refinement")
