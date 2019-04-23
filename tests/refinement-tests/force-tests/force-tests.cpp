#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/force.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("force refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::force_r> |= quantity_t<si::force_t>{}) == quantity_t<si::force_t>{});
}

