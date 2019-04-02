message(STATUS "Building permittivity test")

set(target permittivity-format-test)
message(STATUS "Building library ${target}")

set(sources permittivity-tests.cpp)

add_executable(${target} ${sources})
add_test(permittivity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(permittivity PROPERTIES LABELS "format")
