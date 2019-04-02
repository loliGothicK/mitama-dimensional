#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../format_io_common.hpp"

TEST_CASE("prefix format tests", "[prefix]") {
  REQUIRE(prefix_<std::pico>::str == "p"s);
  REQUIRE(prefix_<std::nano>::str == "n"s);
  REQUIRE(prefix_<std::micro>::str == "u"s);
  REQUIRE(prefix_<std::milli>::str == "m"s);
  REQUIRE(prefix_<std::centi>::str == "c"s);
  REQUIRE(prefix_<std::deci>::str == "d"s);
  REQUIRE(prefix_<std::deca>::str == "da"s);
  REQUIRE(prefix_<std::hecto>::str == "h"s);
  REQUIRE(prefix_<std::kilo>::str == "k"s);
  REQUIRE(prefix_<std::mega>::str == "M"s);
  REQUIRE(prefix_<std::giga>::str == "G"s);
  REQUIRE(prefix_<std::tera>::str == "T"s);
}

TEST_CASE("symbol format tests", "[symbol]") {
  REQUIRE(symbol_<::mitama::si::length>::str == "m"s);
  REQUIRE(symbol_<electric_current>::str == "A"s);
  REQUIRE(symbol_<luminous_intensity>::str == "cd"s);
  REQUIRE(symbol_<thermodynamic_temperature>::str == "K"s);
  REQUIRE(symbol_<::mitama::si::mass>::str == "g"s);
  REQUIRE(symbol_<amount_of_substance>::str == "mol"s);
  REQUIRE(symbol_<::mitama::si::time>::str == "s"s);
}

TEMPLATE_TEST_CASE("meter_t format tests", "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi,
                   std::deci, std::deca, std::hecto, std::kilo, std::mega,
                   std::giga, std::tera) {
  REQUIRE(fmt(test_c<TestType, meter_t>::value) ==
          test_c<TestType, meter_t>::expexted());
}

TEMPLATE_TEST_CASE("ampere_t format tests", "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi,
                   std::deci, std::deca, std::hecto, std::kilo, std::mega,
                   std::giga, std::tera) {
  REQUIRE(fmt(test_c<TestType, ampere_t>::value) ==
          test_c<TestType, ampere_t>::expexted());
}

TEMPLATE_TEST_CASE("candela_t format tests", "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi,
                   std::deci, std::deca, std::hecto, std::kilo, std::mega,
                   std::giga, std::tera) {
  REQUIRE(fmt(test_c<TestType, candela_t>::value) ==
          test_c<TestType, candela_t>::expexted());
}

TEMPLATE_TEST_CASE("kelvin_t format tests", "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi,
                   std::deci, std::deca, std::hecto, std::kilo, std::mega,
                   std::giga, std::tera) {
  REQUIRE(fmt(test_c<TestType, kelvin_t>::value) ==
          test_c<TestType, kelvin_t>::expexted());
}

TEMPLATE_TEST_CASE("mol_t format tests", "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi,
                   std::deci, std::deca, std::hecto, std::kilo, std::mega,
                   std::giga, std::tera) {
  REQUIRE(fmt(test_c<TestType, mol_t>::value) ==
          test_c<TestType, mol_t>::expexted());
}

TEMPLATE_TEST_CASE("second_t format tests", "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi,
                   std::deci, std::deca, std::hecto, std::kilo, std::mega,
                   std::giga, std::tera) {
  REQUIRE(fmt(test_c<TestType, second_t>::value) ==
          test_c<TestType, second_t>::expexted());
}

TEST_CASE("kilogram_t format tests", "[quantity][symbol][prefix]") {
  REQUIRE(fmt(1 | mega * kilograms) == "1 [Gg]");
  REQUIRE(fmt(1 | kilo * kilograms) == "1 [Mg]");
  REQUIRE(fmt(1 | kilograms) == "1 [kg]");
  REQUIRE(fmt(1 | milli * kilograms) == "1 [g]");
  REQUIRE(fmt(1 | micro * kilograms) == "1 [mg]");
}
