message(STATUS "Building spectral_power test")

set(target spectral_power-format-test)
message(STATUS "Building library ${target}")

set(sources spectral_power-tests.cpp)

add_executable(${target} ${sources})
add_test(spectral_power "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(spectral_power PROPERTIES LABELS "format")
