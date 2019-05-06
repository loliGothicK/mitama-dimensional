#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/resistance.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("resistance refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::resistance_r> |= quantity_t<si::resistance_t>{}) == quantity_t<si::resistance_t>{});
}

