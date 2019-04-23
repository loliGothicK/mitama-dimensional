message(STATUS "Building angular_momentum test")

set(target angular_momentum-refinement-test)
message(STATUS "Building library ${target}")

set(sources angular_momentum-tests.cpp)

add_executable(${target} ${sources})
add_test(angular_momentum "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(angular_momentum PROPERTIES LABELS "refinement")
