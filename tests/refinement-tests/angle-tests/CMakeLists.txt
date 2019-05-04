message(STATUS "Building angle test")

set(target angle-refinement-test)
message(STATUS "Building library ${target}")

set(sources angle-tests.cpp)

add_executable(${target} ${sources})
add_test(angle "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(angle PROPERTIES LABELS "refinement")
