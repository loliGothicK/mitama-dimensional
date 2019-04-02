message(STATUS "Building irradiance test")

set(target irradiance-format-test)
message(STATUS "Building library ${target}")

set(sources irradiance-tests.cpp)

add_executable(${target} ${sources})
add_test(irradiance "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(irradiance PROPERTIES LABELS "format")
