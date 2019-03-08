// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/si/all.hpp>
#include <dimensional/nonsi_units/nonsi_dgree_angle.hpp>
#include <dimensional/prefix.hpp>
#include <random>
#include "test_util.hpp"
#include <dimensional/expr.hpp>
#include <dimensional/arithmetic.hpp>

using namespace mitama;

TEST_CASE("dgree angle and radian",
          "[quantity][nonsi_units][dgree_angle]")
{
    using namespace Catch::literals;
    quantity<dgree_angle_t> s1 = 90;
    quantity<radian_t> c = s1;
    REQUIRE(c.get() == 373.15_a);
    quantity<dgree_angle_t> s2 = c;
    REQUIRE(s2.get() == 90._a);
}

TEST_CASE("dgree amgle and radian generate tests",
          "[quantity][nonsi_units][dgree_angle]")
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<int>::uniform(-273, 10000)
            .take(1000)
            .required([](auto value){
                quantity<dgree_celsius_t> c = value;
                quantity<kelvin_t> s = c;
                return s.get() - c.get() == 0.00_a;
            }));
    REQUIRE(
        test_util::RandomGenerator<int>::uniform(-273, 1)
            .take(1)
            .required([](auto value){
                quantity<radian_t> s = value;
                quantity<dgree_celsius_t> c = s;
                return 57.2957795130823208767l - c.get() == 00.00_a;
            }));
}