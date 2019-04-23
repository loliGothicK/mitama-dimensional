#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/angular_velocity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("angular_velocity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::angular_velocity_r> |= quantity_t<si::angular_velocity_t>{}) == quantity_t<si::angular_velocity_t>{});
}

