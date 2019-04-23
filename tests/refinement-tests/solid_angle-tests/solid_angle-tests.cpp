#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/solid_angle.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("solid_angle refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::steradian_r> |= quantity_t<si::steradian_t>{}) == quantity_t<si::steradian_t>{});
}

