message(STATUS "Building test for si-literals")

set(target tests-for-si-literals)
message(STATUS "Building library ${target}")

set(sources
    tests-main.cpp
    ampere-tests.cpp
    # candela-tests.cpp
)
add_executable(${target} ${sources})
add_test(literal-tests "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(literal-tests PROPERTIES LABELS "arithmetic")
