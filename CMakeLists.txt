cmake_minimum_required(VERSION 3.1)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17) # C++17...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11
find_package(Threads REQUIRED)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic-errors")

## Set our project name
project(mitama-dimensional)

include_directories(
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tests
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Catch2/single_include
  )


set(target tests)
set(sources
  tests/tests-main.cpp
	tests/basic-tests.cpp
	tests/arithmetic-tests.cpp
	tests/symbol-io-tests.cpp
)
add_executable(${target} ${sources})
message(STATUS "Building library ${target}...")

add_test(tests "${EXECUTABLE_OUTPUT_PATH}/${target}")
enable_testing()


