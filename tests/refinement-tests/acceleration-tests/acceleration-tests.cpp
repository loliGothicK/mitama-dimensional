#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/acceleration.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("acceleration refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::acceleration_r> |= quantity_t<si::acceleration_t>{}) == quantity_t<si::acceleration_t>{});
}

