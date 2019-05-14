#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/radiant_intensity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("radiant_intensity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::radiant_intensity_r> |= quantity_t<systems::si::radiant_intensity_t>{}) == quantity_t<systems::si::radiant_intensity_t>{});
}

