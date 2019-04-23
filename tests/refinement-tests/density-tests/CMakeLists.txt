message(STATUS "Building density test")

set(target density-refinement-test)
message(STATUS "Building library ${target}")

set(sources density-tests.cpp)

add_executable(${target} ${sources})
add_test(density "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(density PROPERTIES LABELS "refinement")
