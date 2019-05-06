#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/angular_acceleration.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("angular_acceleration refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::angular_acceleration_r> |= quantity_t<si::angular_acceleration_t>{}) == quantity_t<si::angular_acceleration_t>{});
}

