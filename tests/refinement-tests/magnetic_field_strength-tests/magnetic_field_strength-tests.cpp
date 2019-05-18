#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/magnetic_field_strength.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("magnetic_field_strength refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::magnetic_field_strength_r> |= quantity_t<systems::si::magnetic_field_strength_t>{}) == quantity_t<systems::si::magnetic_field_strength_t>{});
}

