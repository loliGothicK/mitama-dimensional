#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/pressure.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("pressure refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::pressure_r> |= quantity_t<systems::si::pressure_t>{}) == quantity_t<systems::si::pressure_t>{});
}

