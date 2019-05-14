#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/molarity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("molarity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::molarity_r> |= quantity_t<systems::si::molarity_t>{}) == quantity_t<systems::si::molarity_t>{});
}

