#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/fuel_efficiency.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("fuel_efficiency refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::fuel_efficiency_r> |= quantity_t<si::fuel_efficiency_t>{}) == quantity_t<si::fuel_efficiency_t>{});
}

