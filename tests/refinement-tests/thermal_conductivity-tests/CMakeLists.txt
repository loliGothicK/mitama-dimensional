message(STATUS "Building thermal_conductivity test")

set(target thermal_conductivity-refinement-test)
message(STATUS "Building library ${target}")

set(sources thermal_conductivity-tests.cpp)

add_executable(${target} ${sources})
add_test(thermal_conductivity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(thermal_conductivity PROPERTIES LABELS "refinement")
