#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/force.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("force refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::force_r> |= quantity_t<systems::si::force_t>{}) == quantity_t<systems::si::force_t>{});
}

