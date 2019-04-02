message(STATUS "Building magnetic_reluctance test")

set(target magnetic_reluctance-format-test)
message(STATUS "Building library ${target}")

set(sources magnetic_reluctance-tests.cpp)

add_executable(${target} ${sources})
add_test(magnetic_reluctance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(magnetic_reluctance PROPERTIES LABELS "format")
