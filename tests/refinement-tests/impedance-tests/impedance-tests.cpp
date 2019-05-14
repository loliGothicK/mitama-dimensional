#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/impedance.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("impedance refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::impedance_r> |= quantity_t<systems::si::impedance_t>{}) == quantity_t<systems::si::impedance_t>{});
}

