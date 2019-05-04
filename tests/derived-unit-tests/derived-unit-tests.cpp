// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/nonsi_units/degree_celsius.hpp>
#include <dimensional/prefix.hpp>
#include <random>
#include <test_util.hpp>
#include <dimensional/expr.hpp>
#include <dimensional/arithmetic.hpp>

using namespace mitama;
using namespace mitama::si;
using namespace mitama::nonsi;

TEST_CASE("degree celsius and kelvin",
          "[quantity][derived-units][temperature]")
{
    using namespace Catch::literals;
    quantity<degree_celsius_t> s1 = 100;
    quantity<kelvin_t> c = s1;
    REQUIRE(c.value() == 373.15_a);
    quantity<degree_celsius_t> s2 = c;
    REQUIRE(s2.value() == 100._a);
}

TEST_CASE("degree celsius and kelvin generate tests",
          "[quantity][derived-units][temperature]")
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<int>::uniform(-273, 10000)
            .take(1000)
            .required([](auto value){
                quantity<degree_celsius_t> c = value;
                quantity<kelvin_t> s = c;
                return s.value() - c.value() == 273.15_a;
            }));
    REQUIRE(
        test_util::RandomGenerator<int>::uniform(-273, 10000)
            .take(1000)
            .required([](auto value){
                quantity<kelvin_t> s = value;
                quantity<degree_celsius_t> c = s;
                return s.value() - c.value() == 273.15_a;
            }));
}

TEST_CASE("degree celsius and kelvin lexical tests",
          "[quantity][derived-units][temperature]")
{
    using namespace Catch::literals;
    {
        quantity<decltype(kelvin<>/mol<>)> _ = as_expr(1|kelvins) / (2|mols) + as_expr(2|degree_celsius) / (2|mols);
        REQUIRE(_.value() == 137.575_a);
    }
    {
        quantity<decltype(kelvin<>/mol<>)> _ = (as_expr(11|kelvins) - as_expr(1|kelvins)) / (2|mols) + (as_expr(21|degree_celsius) - as_expr(1|degree_celsius)) / (2|mols);
        REQUIRE(_.value() == 15._a);
    }
}

