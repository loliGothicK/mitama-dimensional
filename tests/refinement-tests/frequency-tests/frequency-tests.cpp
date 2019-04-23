#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/frequency.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("frequency refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::frequency_r> |= quantity_t<si::frequency_t>{}) == quantity_t<si::frequency_t>{});
}

