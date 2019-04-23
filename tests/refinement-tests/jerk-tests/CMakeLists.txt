message(STATUS "Building jerk test")

set(target jerk-refinement-test)
message(STATUS "Building library ${target}")

set(sources jerk-tests.cpp)

add_executable(${target} ${sources})
add_test(jerk "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(jerk PROPERTIES LABELS "refinement")
