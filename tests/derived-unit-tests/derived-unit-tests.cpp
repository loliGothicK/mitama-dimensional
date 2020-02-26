// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/nonsi/degree_celsius.hpp>
#include <dimensional/systems/si/prefix.hpp>
#include <random>
#include <test_util.hpp>
#include <dimensional/arithmetic.hpp>

using namespace mitama;
using namespace mitama::systems::si;
using namespace mitama::systems::nonsi;

TEST_CASE("degree celsius and kelvin",
          "[quantity][derived-units][temperature]")
{
    using namespace Catch::literals;
    quantity_t<degree_celsius_t> s1 = 100;
    quantity_t<kelvin_t> c = s1;
    REQUIRE(c.value() == 373.15_a);
    quantity_t<degree_celsius_t> s2 = c;
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
                quantity_t<degree_celsius_t> c = value;
                quantity_t<kelvin_t> s = c;
                return s.value() - c.value() == 273.15_a;
            }));
    REQUIRE(
        test_util::RandomGenerator<int>::uniform(-273, 10000)
            .take(1000)
            .required([](auto value){
                quantity_t<kelvin_t> s = value;
                quantity_t<degree_celsius_t> c = s;
                return s.value() - c.value() == 273.15_a;
            }));
}
