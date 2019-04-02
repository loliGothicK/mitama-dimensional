message(STATUS "Building math test")

set(target math-tests)
message(STATUS "Building library ${target}")

set(sources math-tests.cpp tests-main.cpp)

add_executable(${target} ${sources})
add_test(math "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(math PROPERTIES LABELS "math")
