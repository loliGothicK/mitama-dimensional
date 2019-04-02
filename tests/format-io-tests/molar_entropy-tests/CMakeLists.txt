message(STATUS "Building molar_entropy test")

set(target molar_entropy-format-test)
message(STATUS "Building library ${target}")

set(sources molar_entropy-tests.cpp)

add_executable(${target} ${sources})
add_test(molar_entropy "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(molar_entropy PROPERTIES LABELS "format")
