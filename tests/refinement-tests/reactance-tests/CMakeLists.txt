message(STATUS "Building reactance test")

set(target reactance-refinement-test)
message(STATUS "Building library ${target}")

set(sources reactance-tests.cpp)

add_executable(${target} ${sources})
add_test(reactance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(reactance PROPERTIES LABELS "refinement")
