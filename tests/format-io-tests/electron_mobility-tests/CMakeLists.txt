message(STATUS "Building electron_mobility test")

set(target electron_mobility-format-test)
message(STATUS "Building library ${target}")

set(sources electron_mobility-tests.cpp)

add_executable(${target} ${sources})
add_test(electron_mobility "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(electron_mobility PROPERTIES LABELS "format")
