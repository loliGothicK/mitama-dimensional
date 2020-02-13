#!/bin/bash

# Init
cat <<'EOS' > ./CMakeLists.txt
cmake_minimum_required(VERSION 3.1)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17) # ...C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++17
find_package(Threads REQUIRED)
find_package(Boost 1.62.0 REQUIRED
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

EOS

# Configure
ls -1 tests | sed -E 's/(.*)-tests/add_subdirectory(tests\/\1-tests)/g' \
            | grep 'add_subdirectory' \
            | xargs -I@ echo @  >> ./CMakeLists.txt

# Build and Test
mkdir -p build \
    && cd build \
    && cmake .. \
    && make -j5 \
    && ctest 2>&1 | tee ./ctset.log
