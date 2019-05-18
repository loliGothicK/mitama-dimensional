#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/thermal_diffusivity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("thermal_diffusivity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::thermal_diffusivity_r> |= quantity_t<systems::si::thermal_diffusivity_t>{}) == quantity_t<systems::si::thermal_diffusivity_t>{});
}

