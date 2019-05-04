message(STATUS "Building radiant_exposure test")

set(target radiant_exposure-refinement-test)
message(STATUS "Building library ${target}")

set(sources radiant_exposure-tests.cpp)

add_executable(${target} ${sources})
add_test(radiant_exposure "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(radiant_exposure PROPERTIES LABELS "refinement")
