#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/specific_angular_momentum.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("specific_angular_momentum refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::specific_angular_momentum_r> |= quantity_t<si::specific_angular_momentum_t>{}) == quantity_t<si::specific_angular_momentum_t>{});
}

