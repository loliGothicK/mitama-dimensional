#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/voltage.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("voltage refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::voltage_r> |= quantity_t<systems::si::voltage_t>{}) == quantity_t<systems::si::voltage_t>{});
}

