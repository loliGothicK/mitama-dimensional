cmake_minimum_required(VERSION 3.1)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17) # C++17...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11
find_package(Threads REQUIRED)

## Set our project name
project(wizardry-currency)

include_directories(
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include
  )


set(target a.out)
set(sources
  main.cpp
)
add_executable(${target} ${sources})
message(STATUS "Building library ${target}...")


