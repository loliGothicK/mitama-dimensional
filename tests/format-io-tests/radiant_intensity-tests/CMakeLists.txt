message(STATUS "Building radiant_intensity test")

set(target radiant_intensity-format-test)
message(STATUS "Building library ${target}")

set(sources radiant_intensity-tests.cpp)

add_executable(${target} ${sources})
add_test(radiant_intensity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(radiant_intensity PROPERTIES LABELS "format")
