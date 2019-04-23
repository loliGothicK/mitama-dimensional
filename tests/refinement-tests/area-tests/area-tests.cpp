#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/area.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("area refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::area_r> |= quantity_t<si::area_t>{}) == quantity_t<si::area_t>{});
}

