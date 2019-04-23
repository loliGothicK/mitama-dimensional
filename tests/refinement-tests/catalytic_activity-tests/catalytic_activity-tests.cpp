#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/catalytic_activity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("catalytic_activity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::catalytic_activity_r> |= quantity_t<si::catalytic_activity_t>{}) == quantity_t<si::catalytic_activity_t>{});
}

