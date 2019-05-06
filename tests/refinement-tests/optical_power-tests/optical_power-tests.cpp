#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/optical_power.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("optical_power refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::optical_power_r> |= quantity_t<si::optical_power_t>{}) == quantity_t<si::optical_power_t>{});
}

