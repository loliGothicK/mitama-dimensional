#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/systems/si/derived_units/molar_mass.hpp>
#include <mitama/dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("molar_mass refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::molar_mass_r> |= quantity_t<systems::si::molar_mass_t>{}) == quantity_t<systems::si::molar_mass_t>{});
}

