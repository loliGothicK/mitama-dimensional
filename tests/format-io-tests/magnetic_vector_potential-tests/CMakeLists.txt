message(STATUS "Building magnetic_vector_potential test")

set(target magnetic_vector_potential-format-test)
message(STATUS "Building library ${target}")

set(sources magnetic_vector_potential-tests.cpp)

add_executable(${target} ${sources})
add_test(magnetic_vector_potential "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(magnetic_vector_potential PROPERTIES LABELS "format")
