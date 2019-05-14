#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/power_density.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("power_density refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::power_density_r> |= quantity_t<systems::si::power_density_t>{}) == quantity_t<systems::si::power_density_t>{});
}

