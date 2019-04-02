#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/radioactivity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("radioactivity_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::radioactivity_t{}) == "1 [Bq]");
}
TEST_CASE("becquerel format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::becquerel) == "1 [Bq]");
}
