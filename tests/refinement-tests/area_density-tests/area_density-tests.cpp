#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/area_density.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("area_density refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::area_density_r> |= quantity_t<si::area_density_t>{}) == quantity_t<si::area_density_t>{});
}

