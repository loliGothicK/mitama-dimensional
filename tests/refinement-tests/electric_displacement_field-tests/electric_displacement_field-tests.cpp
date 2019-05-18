#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/electric_displacement_field.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("electric_displacement_field refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::electric_displacement_field_r> |= quantity_t<systems::si::electric_displacement_field_t>{}) == quantity_t<systems::si::electric_displacement_field_t>{});
}

