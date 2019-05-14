#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/radioactivity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("radioactivity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::radioactivity_r> |= quantity_t<systems::si::radioactivity_t>{}) == quantity_t<systems::si::radioactivity_t>{});
}

