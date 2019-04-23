message(STATUS "Building pressure test")

set(target pressure-refinement-test)
message(STATUS "Building library ${target}")

set(sources pressure-tests.cpp)

add_executable(${target} ${sources})
add_test(pressure "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(pressure PROPERTIES LABELS "refinement")
