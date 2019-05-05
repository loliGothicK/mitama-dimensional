#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/linear_mass_density.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("linear_mass_density refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::linear_mass_density_r> |= quantity_t<si::linear_mass_density_t>{}) == quantity_t<si::linear_mass_density_t>{});
}

