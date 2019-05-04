message(STATUS "Building thermal_expansion_coefficient test")

set(target thermal_expansion_coefficient-refinement-test)
message(STATUS "Building library ${target}")

set(sources thermal_expansion_coefficient-tests.cpp)

add_executable(${target} ${sources})
add_test(thermal_expansion_coefficient "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(thermal_expansion_coefficient PROPERTIES LABELS "refinement")
