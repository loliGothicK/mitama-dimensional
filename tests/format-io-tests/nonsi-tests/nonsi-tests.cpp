#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/nonsi_units/au.hpp>
#include <dimensional/nonsi_units/day.hpp>
#include <dimensional/nonsi_units/dgree_angle.hpp>
#include <dimensional/nonsi_units/hectare.hpp>
#include <dimensional/nonsi_units/hour.hpp>
#include <dimensional/nonsi_units/liter.hpp>
#include <dimensional/nonsi_units/minute.hpp>
#include <dimensional/nonsi_units/tonne.hpp>
#include <dimensional/nonsi_units/dgree_celsius.hpp>
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
  REQUIRE(fmt(1 | mitama::nonsi::hours) == "1 [h]");
}

TEST_CASE("days format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | days) == "1 [d]");
}

TEST_CASE("dgree_celcius format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | dgree_celsius) == "1 [°C]");
}

