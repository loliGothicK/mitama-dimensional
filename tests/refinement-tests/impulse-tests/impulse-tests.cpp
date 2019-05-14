#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/impulse.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("impulse refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::impulse_r> |= quantity_t<systems::si::impulse_t>{}) == quantity_t<systems::si::impulse_t>{});
}

