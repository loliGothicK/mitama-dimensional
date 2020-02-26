#!/bin/bash
if [ ! -e $1-tests ]; then
    mkdir $1-tests
fi
cat <<EOS > $1-tests/$1-tests.cpp
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/$1.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("$2 format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::$2{}) == "1 [$4]");
}
TEST_CASE("$3 format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::$3) == "1 [$4]");
}
EOS
cat <<EOS > $1-tests/CMakeLists.txt
message(STATUS "Building $1 test")

set(target $1-format-test)
message(STATUS "Building library \${target}")

set(sources $1-tests.cpp)

add_executable(\${target} \${sources})
add_test($1 "\${EXECUTABLE_OUTPUT_PATH}/\${target}")
set_tests_properties($1 PROPERTIES LABELS "format")
EOS
