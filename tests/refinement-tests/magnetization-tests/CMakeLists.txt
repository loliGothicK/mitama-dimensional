message(STATUS "Building magnetization test")

set(target magnetization-refinement-test)
message(STATUS "Building library ${target}")

set(sources magnetization-tests.cpp)

add_executable(${target} ${sources})
add_test(magnetization "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(magnetization PROPERTIES LABELS "refinement")
