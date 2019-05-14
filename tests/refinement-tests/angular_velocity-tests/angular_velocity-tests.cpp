#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/angular_velocity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("angular_velocity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::angular_velocity_r> |= quantity_t<systems::si::angular_velocity_t>{}) == quantity_t<systems::si::angular_velocity_t>{});
}

