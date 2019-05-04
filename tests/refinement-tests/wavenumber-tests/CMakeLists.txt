message(STATUS "Building wavenumber test")

set(target wavenumber-refinement-test)
message(STATUS "Building library ${target}")

set(sources wavenumber-tests.cpp)

add_executable(${target} ${sources})
add_test(wavenumber "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(wavenumber PROPERTIES LABELS "refinement")
