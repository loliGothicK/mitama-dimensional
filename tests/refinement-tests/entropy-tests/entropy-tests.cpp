#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/entropy.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("entropy refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::entropy_r> |= quantity_t<systems::si::entropy_t>{}) == quantity_t<systems::si::entropy_t>{});
}

