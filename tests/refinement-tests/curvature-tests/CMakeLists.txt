message(STATUS "Building curvature test")

set(target curvature-refinement-test)
message(STATUS "Building library ${target}")

set(sources curvature-tests.cpp)

add_executable(${target} ${sources})
add_test(curvature "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(curvature PROPERTIES LABELS "refinement")
