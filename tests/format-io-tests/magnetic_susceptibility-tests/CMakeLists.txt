message(STATUS "Building magnetic_susceptibility test")

set(target magnetic_susceptibility-format-test)
message(STATUS "Building library ${target}")

set(sources magnetic_susceptibility-tests.cpp)

add_executable(${target} ${sources})
add_test(magnetic_susceptibility "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(magnetic_susceptibility PROPERTIES LABELS "format")
