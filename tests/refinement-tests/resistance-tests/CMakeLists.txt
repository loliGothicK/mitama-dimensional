message(STATUS "Building resistance test")

set(target resistance-refinement-test)
message(STATUS "Building library ${target}")

set(sources resistance-tests.cpp)

add_executable(${target} ${sources})
add_test(resistance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(resistance PROPERTIES LABELS "refinement")
