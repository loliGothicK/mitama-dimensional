message(STATUS "Building luminance test")

set(target luminance-refinement-test)
message(STATUS "Building library ${target}")

set(sources luminance-tests.cpp)

add_executable(${target} ${sources})
add_test(luminance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(luminance PROPERTIES LABELS "refinement")
