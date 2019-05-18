#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/molar_heat_capacity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("molar_heat_capacity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::molar_heat_capacity_r> |= quantity_t<systems::si::molar_heat_capacity_t>{}) == quantity_t<systems::si::molar_heat_capacity_t>{});
}

