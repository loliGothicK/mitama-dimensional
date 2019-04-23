message(STATUS "Building specific_entropy test")

set(target specific_entropy-refinement-test)
message(STATUS "Building library ${target}")

set(sources specific_entropy-tests.cpp)

add_executable(${target} ${sources})
add_test(specific_entropy "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(specific_entropy PROPERTIES LABELS "refinement")
