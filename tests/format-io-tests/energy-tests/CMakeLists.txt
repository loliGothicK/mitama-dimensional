message(STATUS "Building energy test")

set(target energy-format-test)
message(STATUS "Building library ${target}")

set(sources energy-tests.cpp)

add_executable(${target} ${sources})
add_test(energy "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(energy PROPERTIES LABELS "format")
