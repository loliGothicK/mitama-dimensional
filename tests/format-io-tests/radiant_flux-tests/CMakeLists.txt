message(STATUS "Building radiant_flux test")

set(target radiant_flux-format-test)
message(STATUS "Building library ${target}")

set(sources radiant_flux-tests.cpp)

add_executable(${target} ${sources})
add_test(radiant_flux "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(radiant_flux PROPERTIES LABELS "format")
