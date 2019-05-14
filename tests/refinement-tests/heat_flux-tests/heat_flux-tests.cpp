#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/heat_flux.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("heat_flux refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::heat_flux_r> |= quantity_t<systems::si::heat_flux_t>{}) == quantity_t<systems::si::heat_flux_t>{});
}

