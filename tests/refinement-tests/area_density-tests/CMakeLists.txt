message(STATUS "Building area_density test")

set(target area_density-refinement-test)
message(STATUS "Building library ${target}")

set(sources area_density-tests.cpp)

add_executable(${target} ${sources})
add_test(area_density "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(area_density PROPERTIES LABELS "refinement")
