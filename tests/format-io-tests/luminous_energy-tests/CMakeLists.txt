message(STATUS "Building luminous_energy test")

set(target luminous_energy-format-test)
message(STATUS "Building library ${target}")

set(sources luminous_energy-tests.cpp)

add_executable(${target} ${sources})
add_test(luminous_energy "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(luminous_energy PROPERTIES LABELS "format")
