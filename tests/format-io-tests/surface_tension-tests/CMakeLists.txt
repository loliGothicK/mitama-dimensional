message(STATUS "Building surface_tension test")

set(target surface_tension-format-test)
message(STATUS "Building library ${target}")

set(sources surface_tension-tests.cpp)

add_executable(${target} ${sources})
add_test(surface_tension "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(surface_tension PROPERTIES LABELS "format")
