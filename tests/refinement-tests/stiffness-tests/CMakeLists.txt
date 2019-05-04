message(STATUS "Building stiffness test")

set(target stiffness-refinement-test)
message(STATUS "Building library ${target}")

set(sources stiffness-tests.cpp)

add_executable(${target} ${sources})
add_test(stiffness "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(stiffness PROPERTIES LABELS "refinement")
