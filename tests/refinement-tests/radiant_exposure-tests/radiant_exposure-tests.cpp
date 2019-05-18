#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/radiant_exposure.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("radiant_exposure refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::radiant_exposure_r> |= quantity_t<systems::si::radiant_exposure_t>{}) == quantity_t<systems::si::radiant_exposure_t>{});
}

