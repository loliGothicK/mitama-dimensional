message(STATUS "Building molar_conductivity test")

set(target molar_conductivity-format-test)
message(STATUS "Building library ${target}")

set(sources molar_conductivity-tests.cpp)

add_executable(${target} ${sources})
add_test(molar_conductivity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(molar_conductivity PROPERTIES LABELS "format")
