#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/catalytic_efficiency.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("catalytic_efficiency refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::catalytic_efficiency_r> |= quantity_t<systems::si::catalytic_efficiency_t>{}) == quantity_t<systems::si::catalytic_efficiency_t>{});
}

