message(STATUS "Building magnetic_rigidity test")

set(target magnetic_rigidity-format-test)
message(STATUS "Building library ${target}")

set(sources magnetic_rigidity-tests.cpp)

add_executable(${target} ${sources})
add_test(magnetic_rigidity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(magnetic_rigidity PROPERTIES LABELS "format")
