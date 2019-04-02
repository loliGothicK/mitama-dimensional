message(STATUS "Building pop test")

set(target pop-format-test)
message(STATUS "Building library ${target}")

set(sources pop-tests.cpp)

add_executable(${target} ${sources})
add_test(pop "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(pop PROPERTIES LABELS "format")
