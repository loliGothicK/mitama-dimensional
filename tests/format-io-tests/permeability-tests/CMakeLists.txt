message(STATUS "Building permeability test")

set(target permeability-format-test)
message(STATUS "Building library ${target}")

set(sources permeability-tests.cpp)

add_executable(${target} ${sources})
add_test(permeability "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(permeability PROPERTIES LABELS "format")
