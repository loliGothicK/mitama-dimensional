#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/thermal_resistance.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("thermal_resistance refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::thermal_resistance_r> |= quantity_t<si::thermal_resistance_t>{}) == quantity_t<si::thermal_resistance_t>{});
}

