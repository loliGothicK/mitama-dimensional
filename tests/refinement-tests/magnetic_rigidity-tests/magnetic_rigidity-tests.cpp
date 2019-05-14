#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/magnetic_rigidity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("magnetic_rigidity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::magnetic_rigidity_r> |= quantity_t<systems::si::magnetic_rigidity_t>{}) == quantity_t<systems::si::magnetic_rigidity_t>{});
}

