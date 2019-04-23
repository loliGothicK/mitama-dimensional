message(STATUS "Building equivalent_dose test")

set(target equivalent_dose-refinement-test)
message(STATUS "Building library ${target}")

set(sources equivalent_dose-tests.cpp)

add_executable(${target} ${sources})
add_test(equivalent_dose "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(equivalent_dose PROPERTIES LABELS "refinement")
