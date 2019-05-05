#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/thermal_expansion_coefficient.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("thermal_expansion_coefficient refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::thermal_expansion_coefficient_r> |= quantity_t<si::thermal_expansion_coefficient_t>{}) == quantity_t<si::thermal_expansion_coefficient_t>{});
}

