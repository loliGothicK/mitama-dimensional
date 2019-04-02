message(STATUS "Building catalytic_efficiency test")

set(target catalytic_efficiency-format-test)
message(STATUS "Building library ${target}")

set(sources catalytic_efficiency-tests.cpp)

add_executable(${target} ${sources})
add_test(catalytic_efficiency "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(catalytic_efficiency PROPERTIES LABELS "format")
