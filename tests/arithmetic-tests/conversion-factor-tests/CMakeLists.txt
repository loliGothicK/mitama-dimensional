message(STATUS "Building conversion-factor test")

set(target conversion-factor-tests)
message(STATUS "Building library ${target}")

set(sources conversion-factor-tests.cpp)
add_executable(${target} ${sources})
add_test(conversion-factor "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(conversion-factor PROPERTIES LABELS "arithmetic")
