#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/power_density.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("power_density refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::power_density_r> |= quantity_t<si::power_density_t>{}) == quantity_t<si::power_density_t>{});
}

