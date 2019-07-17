#!/bin/bash
if [ ! -e $1-tests ]; then
    mkdir $1-tests
fi
cat <<EOS > $1-tests/$1-tests.cpp
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/systems/si/derived_units/$1.hpp>
#include <mitama/dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("$1 refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::$1_r> |= quantity_t<systems::si::$1_t>{}) == quantity_t<systems::si::$1_t>{});
}

EOS
cat <<EOS > $1-tests/CMakeLists.txt
message(STATUS "Building $1 test")

set(target $1-refinement-test)
message(STATUS "Building library \${target}")

set(sources $1-tests.cpp)

add_executable(\${target} \${sources})
add_test($1 "\${EXECUTABLE_OUTPUT_PATH}/\${target}")
set_tests_properties($1 PROPERTIES LABELS "refinement")
EOS
