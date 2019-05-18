#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/magnetic_vector_potential.hpp>
#include "../format_io_common.hpp"

TEST_CASE("magnetic_vector_potential format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::magnetic_vector_potential_t{}) == "1 [Wb/m]");
}
TEST_CASE("magnetic_vector_potential quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::magnetic_vector_potential) == "1 [Wb/m]");
}
TEST_CASE("magnetic_vector_potential type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::magnetic_vector_potential)>, mitama::quantity_t<std::decay_t<decltype(meter<>*kilogram<>*second<-2>*ampere<-1>)>>>);
}
