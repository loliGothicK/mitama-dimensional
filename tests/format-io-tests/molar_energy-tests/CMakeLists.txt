message(STATUS "Building molar_energy test")

set(target molar_energy-format-test)
message(STATUS "Building library ${target}")

set(sources molar_energy-tests.cpp)

add_executable(${target} ${sources})
add_test(molar_energy "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(molar_energy PROPERTIES LABELS "format")
