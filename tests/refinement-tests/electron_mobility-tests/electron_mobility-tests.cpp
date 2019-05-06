#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/electron_mobility.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("electron_mobility refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::electron_mobility_r> |= quantity_t<si::electron_mobility_t>{}) == quantity_t<si::electron_mobility_t>{});
}

