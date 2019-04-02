message(STATUS "Building molar_heat_capacity test")

set(target molar_heat_capacity-format-test)
message(STATUS "Building library ${target}")

set(sources molar_heat_capacity-tests.cpp)

add_executable(${target} ${sources})
add_test(molar_heat_capacity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(molar_heat_capacity PROPERTIES LABELS "format")
