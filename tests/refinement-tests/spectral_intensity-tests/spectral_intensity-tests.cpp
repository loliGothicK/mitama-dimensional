#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/systems/si/derived_units/spectral_intensity.hpp>
#include <mitama/dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("spectral_intensity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::spectral_intensity_r> |= quantity_t<systems::si::spectral_intensity_t>{}) == quantity_t<systems::si::spectral_intensity_t>{});
}

