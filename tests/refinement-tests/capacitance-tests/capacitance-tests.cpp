#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/capacitance.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("capacitance refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::capacitance_r> |= quantity_t<si::capacitance_t>{}) == quantity_t<si::capacitance_t>{});
}

