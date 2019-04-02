message(STATUS "Building derived-unit test")

set(target derived-unit-tests)
message(STATUS "Building library ${target}")

set(sources derived-unit-tests.cpp tests-main.cpp)

add_executable(${target} ${sources})
add_test(derived-unit "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(derived-unit PROPERTIES LABELS "derived-unit")
