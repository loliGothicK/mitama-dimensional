message(STATUS "Building force test")

set(target force-refinement-test)
message(STATUS "Building library ${target}")

set(sources force-tests.cpp)

add_executable(${target} ${sources})
add_test(force "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(force PROPERTIES LABELS "refinement")
