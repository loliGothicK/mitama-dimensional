message(STATUS "Building spectral_radiance test")

set(target spectral_radiance-refinement-test)
message(STATUS "Building library ${target}")

set(sources spectral_radiance-tests.cpp)

add_executable(${target} ${sources})
add_test(spectral_radiance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(spectral_radiance PROPERTIES LABELS "refinement")
