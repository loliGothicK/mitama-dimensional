message(STATUS "Building electrical_conductivity test")

set(target electrical_conductivity-refinement-test)
message(STATUS "Building library ${target}")

set(sources electrical_conductivity-tests.cpp)

add_executable(${target} ${sources})
add_test(electrical_conductivity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(electrical_conductivity PROPERTIES LABELS "refinement")
