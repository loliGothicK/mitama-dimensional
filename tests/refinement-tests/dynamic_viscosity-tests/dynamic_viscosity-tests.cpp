#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/dynamic_viscosity.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("dynamic_viscosity refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::dynamic_viscosity_r> |= quantity_t<si::dynamic_viscosity_t>{}) == quantity_t<si::dynamic_viscosity_t>{});
}

