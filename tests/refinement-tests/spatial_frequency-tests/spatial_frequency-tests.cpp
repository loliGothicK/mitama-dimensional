#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/spatial_frequency.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("spatial_frequency refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::spatial_frequency_r> |= quantity_t<systems::si::spatial_frequency_t>{}) == quantity_t<systems::si::spatial_frequency_t>{});
}

