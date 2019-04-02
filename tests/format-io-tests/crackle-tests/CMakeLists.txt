message(STATUS "Building crackle test")

set(target crackle-format-test)
message(STATUS "Building library ${target}")

set(sources crackle-tests.cpp)

add_executable(${target} ${sources})
add_test(crackle "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(crackle PROPERTIES LABELS "format")
