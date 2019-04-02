message(STATUS "Building luminous_flux test")

set(target luminous_flux-format-test)
message(STATUS "Building library ${target}")

set(sources luminous_flux-tests.cpp)

add_executable(${target} ${sources})
add_test(luminous_flux "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(luminous_flux PROPERTIES LABELS "format")
