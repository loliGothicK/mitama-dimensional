message(STATUS "Building magnetic_flux test")

set(target magnetic_flux-format-test)
message(STATUS "Building library ${target}")

set(sources magnetic_flux-tests.cpp)

add_executable(${target} ${sources})
add_test(magnetic_flux "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(magnetic_flux PROPERTIES LABELS "format")
