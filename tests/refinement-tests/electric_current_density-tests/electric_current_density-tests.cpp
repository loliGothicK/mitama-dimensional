#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/electric_current_density.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("electric_current_density refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::electric_current_density_r> |= quantity_t<systems::si::electric_current_density_t>{}) == quantity_t<systems::si::electric_current_density_t>{});
}

