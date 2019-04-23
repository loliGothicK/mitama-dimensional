message(STATUS "Building molar_mass test")

set(target molar_mass-refinement-test)
message(STATUS "Building library ${target}")

set(sources molar_mass-tests.cpp)

add_executable(${target} ${sources})
add_test(molar_mass "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(molar_mass PROPERTIES LABELS "refinement")
