#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/magnetic_dipole_moment.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("magnetic_dipole_moment refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::magnetic_dipole_moment_r> |= quantity_t<systems::si::magnetic_dipole_moment_t>{}) == quantity_t<systems::si::magnetic_dipole_moment_t>{});
}

