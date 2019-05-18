#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/catalytic_activity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("catalytic_activity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::catalytic_activity_r> |= quantity_t<systems::si::catalytic_activity_t>{}) == quantity_t<systems::si::catalytic_activity_t>{});
}

