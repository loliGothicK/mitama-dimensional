message(STATUS "Building nonsi-tests test")

set(target nonsi-tests-format-test)
message(STATUS "Building library ")

set(sources nonsi-tests.cpp)

add_executable(${target} ${sources})
add_test(nonsi "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(nonsi PROPERTIES LABELS "format")
