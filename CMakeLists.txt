cmake_minimum_required(VERSION 3.1)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17) # ...C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++17
find_package(Threads REQUIRED)
find_package(Boost 1.71.0 REQUIRED
  COMPONENTS
  stacktrace_addr2line
)
## Set our project name
project(mitama-dimensional)

include_directories(
  PUBLIC ${Boost_INCLUDE_DIRS}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tests
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mitama-cpp-result/include
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/catch2/single_include
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_include
  )

if(MSVC)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
endif()

enable_testing()

add_subdirectory(tests/arithmetic-tests)
add_subdirectory(tests/basic-tests)
add_subdirectory(tests/delta-tests)
add_subdirectory(tests/derived-unit-tests)
add_subdirectory(tests/format-io-tests)
add_subdirectory(tests/math-tests)
add_subdirectory(tests/nonsi-unit-tests)
add_subdirectory(tests/refinement-tests)
add_subdirectory(tests/static-quantity-tests)
