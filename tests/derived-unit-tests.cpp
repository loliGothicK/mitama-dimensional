// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/si/all.hpp>
#include <dimensional/derived_units/dgree_celsius.hpp>
#include <dimensional/prefix.hpp>
#include <random>
#include "test_util.hpp"
#include <dimensional/expr.hpp>
#include <dimensional/arithmetic.hpp>

using namespace mitama;

TEST_CASE("dgree celsius and kelvin",
          "[quantity][derived-units][temperature]")
{
    using namespace Catch::literals;
    quantity<dgree_celsius_t> s1 = 100;
    quantity<kelvin_t> c = s1;
    REQUIRE(c.get() == 373.15_a);
    quantity<dgree_celsius_t> s2 = c;
    REQUIRE(s2.get() == 100._a);
}

TEST_CASE("dgree celsius and kelvin generate tests",
          "[quantity][derived-units][temperature]")
{
    using namespace Catch::literals;
    std::mt19937_64 mt{std::random_device{}()};
    std::uniform_int_distribution<> dist{-273, 10000};

    for (std::size_t i{}; i < 100; i++) {
        {
        quantity<dgree_celsius_t> c = dist(mt);
        quantity<kelvin_t> s = c;
        REQUIRE(s.get() - c.get() == 273.15_a);
        }
        {
        quantity<kelvin_t> s = dist(mt);
        quantity<dgree_celsius_t> c = s;
        REQUIRE(s.get() - c.get() == 273.15_a);
        }
    }
}

TEST_CASE("dgree celsius and kelvin lexical tests",
          "[quantity][derived-units][temperature]")
{
    using namespace Catch::literals;
    {
        quantity<decltype(kelvin<>/mol<>)> _ = as_expr(1|kelvins) / (2|mols) + as_expr(2|dgree_celsius) / (2|mols);
        REQUIRE(_.get() == 137.575_a);
    }
    {
        quantity<decltype(kelvin<>/mol<>)> _ = (as_expr(11|kelvins) - as_expr(1|kelvins)) / (2|mols) + (as_expr(21|dgree_celsius) - as_expr(1|dgree_celsius)) / (2|mols);
        REQUIRE(_.get() == 15._a);
    }
}

