#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/magnetic_dipole_moment.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("magnetic_dipole_moment refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::magnetic_dipole_moment_r> |= quantity_t<si::magnetic_dipole_moment_t>{}) == quantity_t<si::magnetic_dipole_moment_t>{});
}

