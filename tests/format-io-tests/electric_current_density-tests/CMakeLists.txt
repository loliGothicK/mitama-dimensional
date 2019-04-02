message(STATUS "Building electric_current_density test")

set(target electric_current_density-format-test)
message(STATUS "Building library ${target}")

set(sources electric_current_density-tests.cpp)

add_executable(${target} ${sources})
add_test(electric_current_density "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(electric_current_density PROPERTIES LABELS "format")
