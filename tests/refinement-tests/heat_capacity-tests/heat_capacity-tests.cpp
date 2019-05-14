#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/heat_capacity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("heat_capacity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::heat_capacity_r> |= quantity_t<systems::si::heat_capacity_t>{}) == quantity_t<systems::si::heat_capacity_t>{});
}

