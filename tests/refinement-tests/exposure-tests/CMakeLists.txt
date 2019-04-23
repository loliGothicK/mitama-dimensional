message(STATUS "Building exposure test")

set(target exposure-refinement-test)
message(STATUS "Building library ${target}")

set(sources exposure-tests.cpp)

add_executable(${target} ${sources})
add_test(exposure "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(exposure PROPERTIES LABELS "refinement")
