#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/nonsi/au.hpp>
#include <mitama/dimensional/systems/nonsi/day.hpp>
#include <mitama/dimensional/systems/nonsi/degree_angle.hpp>
#include <mitama/dimensional/systems/nonsi/hectare.hpp>
#include <mitama/dimensional/systems/nonsi/hour.hpp>
#include <mitama/dimensional/systems/nonsi/liter.hpp>
#include <mitama/dimensional/systems/nonsi/minute.hpp>
#include <mitama/dimensional/systems/nonsi/tonne.hpp>
#include <mitama/dimensional/systems/nonsi/degree_celsius.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("hectare format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | hectare) == "1 [ha]");
}

TEST_CASE("litre format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | litre) == "1 [L]");
}

TEST_CASE("liter format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | liter) == "1 [L]");
}

TEST_CASE("tonne format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | tonne) == "1 [t]");
}

TEST_CASE("au format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | au) == "1 [au]");
}

TEST_CASE("minutes format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | minutes) == "1 [m]");
}

TEST_CASE("hours format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | mitama::systems::nonsi::hours) == "1 [h]");
}

TEST_CASE("days format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | days) == "1 [d]");
}

TEST_CASE("degree_celcius format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | degree_celsius) == "1 [°C]");
}

