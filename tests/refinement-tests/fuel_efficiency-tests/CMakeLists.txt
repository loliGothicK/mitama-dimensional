message(STATUS "Building fuel_efficiency test")

set(target fuel_efficiency-refinement-test)
message(STATUS "Building library ${target}")

set(sources fuel_efficiency-tests.cpp)

add_executable(${target} ${sources})
add_test(fuel_efficiency "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(fuel_efficiency PROPERTIES LABELS "refinement")
