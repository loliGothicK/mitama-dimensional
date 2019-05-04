message(STATUS "Building specific_angular_momentum test")

set(target specific_angular_momentum-refinement-test)
message(STATUS "Building library ${target}")

set(sources specific_angular_momentum-tests.cpp)

add_executable(${target} ${sources})
add_test(specific_angular_momentum "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(specific_angular_momentum PROPERTIES LABELS "refinement")
