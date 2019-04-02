message(STATUS "Building luminous_exposure test")

set(target luminous_exposure-format-test)
message(STATUS "Building library ${target}")

set(sources luminous_exposure-tests.cpp)

add_executable(${target} ${sources})
add_test(luminous_exposure "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(luminous_exposure PROPERTIES LABELS "format")
