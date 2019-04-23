message(STATUS "Building radiance test")

set(target radiance-refinement-test)
message(STATUS "Building library ${target}")

set(sources radiance-tests.cpp)

add_executable(${target} ${sources})
add_test(radiance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(radiance PROPERTIES LABELS "refinement")
