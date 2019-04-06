message(STATUS "Building subtraction test")

set(target subtraction-tests)
message(STATUS "Building library ${target}")

set(sources subtraction-tests.cpp)
add_executable(${target} ${sources})
add_test(subtraction-tests "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(subtraction-tests PROPERTIES LABELS "arithmetic")
