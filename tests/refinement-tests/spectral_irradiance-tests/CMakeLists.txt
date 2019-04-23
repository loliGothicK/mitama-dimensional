message(STATUS "Building spectral_irradiance test")

set(target spectral_irradiance-refinement-test)
message(STATUS "Building library ${target}")

set(sources spectral_irradiance-tests.cpp)

add_executable(${target} ${sources})
add_test(spectral_irradiance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(spectral_irradiance PROPERTIES LABELS "refinement")
