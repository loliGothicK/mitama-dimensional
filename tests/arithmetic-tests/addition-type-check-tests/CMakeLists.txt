message(STATUS "Building addition-type-check test")

set(target addition-type-check-tests)
message(STATUS "Building library ${target}")

set(sources addition-type-check-tests.cpp)
add_executable(${target} ${sources})
add_test(addition-type-check "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(addition-type-check PROPERTIES LABELS "arithmetic")
