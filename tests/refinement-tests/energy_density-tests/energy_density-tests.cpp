#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/energy_density.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("energy_density refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::energy_density_r> |= quantity_t<si::energy_density_t>{}) == quantity_t<si::energy_density_t>{});
}

