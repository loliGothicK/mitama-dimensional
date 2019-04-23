#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/electric_current_density.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("electric_current_density refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::electric_current_density_r> |= quantity_t<si::electric_current_density_t>{}) == quantity_t<si::electric_current_density_t>{});
}

