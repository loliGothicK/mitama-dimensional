message(STATUS "Building diffusion_coefficient test")

set(target diffusion_coefficient-format-test)
message(STATUS "Building library ${target}")

set(sources diffusion_coefficient-tests.cpp)

add_executable(${target} ${sources})
add_test(diffusion_coefficient "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(diffusion_coefficient PROPERTIES LABELS "format")
