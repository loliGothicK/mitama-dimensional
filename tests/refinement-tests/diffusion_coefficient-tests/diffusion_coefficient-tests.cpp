#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/diffusion_coefficient.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("diffusion_coefficient refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::diffusion_coefficient_r> |= quantity_t<si::diffusion_coefficient_t>{}) == quantity_t<si::diffusion_coefficient_t>{});
}

