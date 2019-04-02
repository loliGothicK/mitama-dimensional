message(STATUS "Building nonsi-unit test")

set(target nonsi-unit-tests)
message(STATUS "Building library ${target}")

set(sources nonsi-unit-tests.cpp tests-main.cpp)

add_executable(${target} ${sources})
add_test(nonsi-unit "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(nonsi-unit PROPERTIES LABELS "nonsi-unit")
