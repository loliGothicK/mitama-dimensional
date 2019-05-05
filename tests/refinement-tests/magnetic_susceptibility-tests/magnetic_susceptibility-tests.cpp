#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/magnetic_susceptibility.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("magnetic_susceptibility refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::magnetic_susceptibility_r> |= quantity_t<si::magnetic_susceptibility_t>{}) == quantity_t<si::magnetic_susceptibility_t>{});
}

