#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/spectral_irradiance.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("spectral_irradiance refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::spectral_irradiance_r> |= quantity_t<si::spectral_irradiance_t>{}) == quantity_t<si::spectral_irradiance_t>{});
}

