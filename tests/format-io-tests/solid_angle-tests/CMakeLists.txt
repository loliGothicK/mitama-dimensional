message(STATUS "Building solid_angle test")

set(target solid_angle-format-test)
message(STATUS "Building library ${target}")

set(sources solid_angle-tests.cpp)

add_executable(${target} ${sources})
add_test(solid_angle "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(solid_angle PROPERTIES LABELS "format")
