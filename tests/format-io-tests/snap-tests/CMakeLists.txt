message(STATUS "Building snap test")

set(target snap-format-test)
message(STATUS "Building library ${target}")

set(sources snap-tests.cpp)

add_executable(${target} ${sources})
add_test(snap "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(snap PROPERTIES LABELS "format")
