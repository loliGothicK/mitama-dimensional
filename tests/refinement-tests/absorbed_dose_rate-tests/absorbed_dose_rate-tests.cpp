#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/absorbed_dose_rate.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("absorbed_dose_rate refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::absorbed_dose_rate_r> |= quantity_t<systems::si::absorbed_dose_rate_t>{}) == quantity_t<systems::si::absorbed_dose_rate_t>{});
}

