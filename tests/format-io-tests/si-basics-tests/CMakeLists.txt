message(STATUS "Building si-basics-tests test")

set(target si-basics-tests-format-test)
message(STATUS "Building library ")

set(sources si-basics-tests.cpp)

add_executable(${target} ${sources})
add_test(si-basics "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(si-basics PROPERTIES LABELS "format")
