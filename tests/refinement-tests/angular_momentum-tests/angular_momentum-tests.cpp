#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/angular_momentum.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("angular_momentum refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::angular_momentum_r> |= quantity_t<si::angular_momentum_t>{}) == quantity_t<si::angular_momentum_t>{});
}

