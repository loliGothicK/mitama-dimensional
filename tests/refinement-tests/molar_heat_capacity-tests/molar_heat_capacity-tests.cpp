#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/molar_heat_capacity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("molar_heat_capacity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::molar_heat_capacity_r> |= quantity_t<si::molar_heat_capacity_t>{}) == quantity_t<si::molar_heat_capacity_t>{});
}

