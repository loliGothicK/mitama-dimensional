message(STATUS "Building compressibility test")

set(target compressibility-refinement-test)
message(STATUS "Building library ${target}")

set(sources compressibility-tests.cpp)

add_executable(${target} ${sources})
add_test(compressibility "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(compressibility PROPERTIES LABELS "refinement")
