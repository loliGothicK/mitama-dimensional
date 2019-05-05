#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/luminous_exposure.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("luminous_exposure refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::luminous_exposure_r> |= quantity_t<si::luminous_exposure_t>{}) == quantity_t<si::luminous_exposure_t>{});
}

