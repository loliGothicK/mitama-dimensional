message(STATUS "Building magnetic_dipole_moment test")

set(target magnetic_dipole_moment-format-test)
message(STATUS "Building library ${target}")

set(sources magnetic_dipole_moment-tests.cpp)

add_executable(${target} ${sources})
add_test(magnetic_dipole_moment "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(magnetic_dipole_moment PROPERTIES LABELS "format")
