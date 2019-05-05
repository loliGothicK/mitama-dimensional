#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/spectral_intensity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("spectral_intensity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::spectral_intensity_r> |= quantity_t<si::spectral_intensity_t>{}) == quantity_t<si::spectral_intensity_t>{});
}

