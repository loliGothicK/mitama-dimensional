#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/dynamic_viscosity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("dynamic_viscosity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::dynamic_viscosity_r> |= quantity_t<systems::si::dynamic_viscosity_t>{}) == quantity_t<systems::si::dynamic_viscosity_t>{});
}

