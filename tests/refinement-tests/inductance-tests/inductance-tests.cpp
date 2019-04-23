#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/inductance.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("inductance refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::inductance_r> |= quantity_t<si::inductance_t>{}) == quantity_t<si::inductance_t>{});
}

