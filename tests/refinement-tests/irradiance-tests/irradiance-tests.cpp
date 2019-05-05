#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/irradiance.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("irradiance refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::irradiance_r> |= quantity_t<si::irradiance_t>{}) == quantity_t<si::irradiance_t>{});
}

