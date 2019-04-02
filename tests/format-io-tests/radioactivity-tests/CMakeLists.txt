message(STATUS "Building radioactivity test")

set(target radioactivity-format-test)
message(STATUS "Building library ${target}")

set(sources radioactivity-tests.cpp)

add_executable(${target} ${sources})
add_test(radioactivity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(radioactivity PROPERTIES LABELS "format")
