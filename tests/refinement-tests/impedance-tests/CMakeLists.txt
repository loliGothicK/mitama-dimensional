message(STATUS "Building impedance test")

set(target impedance-refinement-test)
message(STATUS "Building library ${target}")

set(sources impedance-tests.cpp)

add_executable(${target} ${sources})
add_test(impedance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(impedance PROPERTIES LABELS "refinement")
