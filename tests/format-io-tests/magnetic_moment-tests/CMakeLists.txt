message(STATUS "Building magnetic_moment test")

set(target magnetic_moment-format-test)
message(STATUS "Building library ${target}")

set(sources magnetic_moment-tests.cpp)

add_executable(${target} ${sources})
add_test(magnetic_moment "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(magnetic_moment PROPERTIES LABELS "format")
