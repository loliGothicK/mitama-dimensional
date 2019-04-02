message(STATUS "Building spectral_intensity test")

set(target spectral_intensity-format-test)
message(STATUS "Building library ${target}")

set(sources spectral_intensity-tests.cpp)

add_executable(${target} ${sources})
add_test(spectral_intensity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(spectral_intensity PROPERTIES LABELS "format")
