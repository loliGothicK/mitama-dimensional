#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/momentum.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("momentum refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::momentum_r> |= quantity_t<si::momentum_t>{}) == quantity_t<si::momentum_t>{});
}

