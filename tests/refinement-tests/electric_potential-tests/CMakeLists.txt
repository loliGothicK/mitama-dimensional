message(STATUS "Building electric_potential test")

set(target electric_potential-refinement-test)
message(STATUS "Building library ${target}")

set(sources electric_potential-tests.cpp)

add_executable(${target} ${sources})
add_test(electric_potential "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(electric_potential PROPERTIES LABELS "refinement")
