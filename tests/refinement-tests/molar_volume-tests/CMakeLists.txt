message(STATUS "Building molar_volume test")

set(target molar_volume-refinement-test)
message(STATUS "Building library ${target}")

set(sources molar_volume-tests.cpp)

add_executable(${target} ${sources})
add_test(molar_volume "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(molar_volume PROPERTIES LABELS "refinement")
