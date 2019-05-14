#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/momentum.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("momentum refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::momentum_r> |= quantity_t<systems::si::momentum_t>{}) == quantity_t<systems::si::momentum_t>{});
}

