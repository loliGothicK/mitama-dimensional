#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/luminous_efficacy.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("luminous_efficacy refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::luminous_efficacy_r> |= quantity_t<si::luminous_efficacy_t>{}) == quantity_t<si::luminous_efficacy_t>{});
}

