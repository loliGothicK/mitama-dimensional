#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/moment_of_inertia.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("moment_of_inertia refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::moment_of_inertia_r> |= quantity_t<systems::si::moment_of_inertia_t>{}) == quantity_t<systems::si::moment_of_inertia_t>{});
}

