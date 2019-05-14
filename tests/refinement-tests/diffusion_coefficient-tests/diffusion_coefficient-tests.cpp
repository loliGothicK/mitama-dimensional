#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/diffusion_coefficient.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("diffusion_coefficient refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::diffusion_coefficient_r> |= quantity_t<systems::si::diffusion_coefficient_t>{}) == quantity_t<systems::si::diffusion_coefficient_t>{});
}

