#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/luminous_exposure.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("luminous_exposure refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::luminous_exposure_r> |= quantity_t<systems::si::luminous_exposure_t>{}) == quantity_t<systems::si::luminous_exposure_t>{});
}

