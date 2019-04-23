message(STATUS "Building moment_of_inertia test")

set(target moment_of_inertia-refinement-test)
message(STATUS "Building library ${target}")

set(sources moment_of_inertia-tests.cpp)

add_executable(${target} ${sources})
add_test(moment_of_inertia "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(moment_of_inertia PROPERTIES LABELS "refinement")
