#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/magnetic_dipole_moment.hpp>
#include "../format_io_common.hpp"

TEST_CASE("magnetic_dipole_moment format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::magnetic_dipole_moment_t{}) == "1 [J/T]");
}
TEST_CASE("magnetic_dipole_moment quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::magnetic_dipole_moment) == "1 [J/T]");
}
TEST_CASE("magnetic_dipole_moment type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::magnetic_dipole_moment)>, mitama::quantity_t<std::decay_t<decltype(meter<2>*ampere<>)>>>);
}
