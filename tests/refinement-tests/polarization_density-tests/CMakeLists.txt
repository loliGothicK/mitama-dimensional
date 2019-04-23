message(STATUS "Building polarization_density test")

set(target polarization_density-refinement-test)
message(STATUS "Building library ${target}")

set(sources polarization_density-tests.cpp)

add_executable(${target} ${sources})
add_test(polarization_density "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(polarization_density PROPERTIES LABELS "refinement")
