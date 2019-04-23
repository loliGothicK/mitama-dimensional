message(STATUS "Building power test")

set(target power-refinement-test)
message(STATUS "Building library ${target}")

set(sources power-tests.cpp)

add_executable(${target} ${sources})
add_test(power "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(power PROPERTIES LABELS "refinement")
