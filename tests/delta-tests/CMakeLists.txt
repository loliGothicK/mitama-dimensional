message(STATUS "Building delta test")

set(target delta-tests)
message(STATUS "Building library ${target}")

set(sources delta-tests.cpp tests-main.cpp)

add_executable(${target} ${sources})
add_test(delta "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(delta PROPERTIES LABELS "delta")
