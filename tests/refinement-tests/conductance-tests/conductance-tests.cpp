#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/conductance.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("conductance refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::conductance_r> |= quantity_t<si::conductance_t>{}) == quantity_t<si::conductance_t>{});
}

