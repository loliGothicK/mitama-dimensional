message(STATUS "Building absorbed_dose test")

set(target absorbed_dose-refinement-test)
message(STATUS "Building library ${target}")

set(sources absorbed_dose-tests.cpp)

add_executable(${target} ${sources})
add_test(absorbed_dose "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(absorbed_dose PROPERTIES LABELS "refinement")
