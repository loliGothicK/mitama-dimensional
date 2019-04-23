message(STATUS "Building luminous_efficacy test")

set(target luminous_efficacy-refinement-test)
message(STATUS "Building library ${target}")

set(sources luminous_efficacy-tests.cpp)

add_executable(${target} ${sources})
add_test(luminous_efficacy "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(luminous_efficacy PROPERTIES LABELS "refinement")
