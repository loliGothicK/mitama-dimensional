message(STATUS "Building specific_energy test")

set(target specific_energy-format-test)
message(STATUS "Building library ${target}")

set(sources specific_energy-tests.cpp)

add_executable(${target} ${sources})
add_test(specific_energy "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(specific_energy PROPERTIES LABELS "format")
