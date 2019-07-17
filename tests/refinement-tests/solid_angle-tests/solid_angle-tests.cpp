#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/systems/si/derived_units/solid_angle.hpp>
#include <mitama/dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("solid_angle refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::steradian_r> |= quantity_t<systems::si::steradian_t>{}) == quantity_t<systems::si::steradian_t>{});
}

