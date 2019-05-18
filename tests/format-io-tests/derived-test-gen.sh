#!/bin/bash
if [ ! -e $1-tests ]; then
    mkdir $1-tests
fi
cat <<EOS > $1-tests/$1-tests.cpp
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/$1.hpp>
#include "../format_io_common.hpp"

TEST_CASE("$1 format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::$1_t{}) == "1 [$2]");
}
TEST_CASE("$1 quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::$1) == "1 [$2]");
}
TEST_CASE("$1 type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::$1)>, mitama::quantity_t<std::decay_t<decltype($3)>>>);
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
