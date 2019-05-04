message(STATUS "Building absorbed_dose_rate test")

set(target absorbed_dose_rate-refinement-test)
message(STATUS "Building library ${target}")

set(sources absorbed_dose_rate-tests.cpp)

add_executable(${target} ${sources})
add_test(absorbed_dose_rate "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(absorbed_dose_rate PROPERTIES LABELS "refinement")
