message(STATUS "Building static-quantity test")

set(target static-quantity-tests)
message(STATUS "Building library ${target}")

set(sources static-quantity-tests.cpp tests-main.cpp)

add_executable(${target} ${sources})
add_test(static-quantity "${EXECUTABLE_OUTPUT_PATH}/${target}")
set_tests_properties(static-quantity PROPERTIES LABELS "static-quantity")
