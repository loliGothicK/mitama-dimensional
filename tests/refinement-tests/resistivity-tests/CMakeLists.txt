message(STATUS "Building resistivity test")

set(target resistivity-refinement-test)
message(STATUS "Building library ${target}")

set(sources resistivity-tests.cpp)

add_executable(${target} ${sources})
add_test(resistivity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(resistivity PROPERTIES LABELS "refinement")
