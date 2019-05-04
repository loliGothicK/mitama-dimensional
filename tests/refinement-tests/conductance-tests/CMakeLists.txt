message(STATUS "Building conductance test")

set(target conductance-refinement-test)
message(STATUS "Building library ${target}")

set(sources conductance-tests.cpp)

add_executable(${target} ${sources})
add_test(conductance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(conductance PROPERTIES LABELS "refinement")
