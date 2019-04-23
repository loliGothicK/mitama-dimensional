#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/luminance.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("luminance refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::luminance_r> |= quantity_t<si::luminance_t>{}) == quantity_t<si::luminance_t>{});
}

