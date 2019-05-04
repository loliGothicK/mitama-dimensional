#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/surface_tension.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("surface_tension refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::surface_tension_r> |= quantity_t<si::surface_tension_t>{}) == quantity_t<si::surface_tension_t>{});
}

