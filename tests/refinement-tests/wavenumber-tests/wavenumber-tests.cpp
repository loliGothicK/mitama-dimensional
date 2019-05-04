#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/wavenumber.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("wavenumber refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::wavenumber_r> |= quantity_t<si::wavenumber_t>{}) == quantity_t<si::wavenumber_t>{});
}

