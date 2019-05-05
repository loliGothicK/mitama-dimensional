#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/magnetic_flux.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("magnetic_flux refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::magnetic_flux_r> |= quantity_t<si::magnetic_flux_t>{}) == quantity_t<si::magnetic_flux_t>{});
}

