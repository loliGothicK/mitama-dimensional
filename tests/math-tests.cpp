// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/si/all.hpp>
#include <dimensional/prefix.hpp>
#include <random>
#include "test_util.hpp"
#include <dimensional/expr.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/math/all.hpp>
#include <dimensional/derived_units/named_units.hpp>

using namespace mitama;

TEST_CASE("sin for radian", "[math],[quantity],[sin]")
{
    quantity<radian_t> rad = 3 | radian;
    REQUIRE(sin(rad) == std::sin(3));
}

TEMPLATE_TEST_CASE("sin with arg not radian", "[math],[quantity],[sin]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE(IS_INVALID_EXPR(sin(DECLVAL(0)))(quantity<TestType>));
}

TEST_CASE("cos for radian", "[math],[quantity],[cos]")
{
    quantity<radian_t> rad = 3 | radian;
    REQUIRE(cos(rad) == std::cos(3));
}

TEMPLATE_TEST_CASE("cos with arg not radian", "[math],[quantity],[cos]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE(IS_INVALID_EXPR(cos(DECLVAL(0)))(quantity<TestType>));
}

TEST_CASE("tan for radian", "[math],[quantity],[tan]")
{
    quantity<radian_t> rad = 3 | radian;
    REQUIRE(tan(rad) == std::tan(3));
}

TEMPLATE_TEST_CASE("tan with arg not radian", "[math],[quantity],[tan]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE(IS_INVALID_EXPR(tan(DECLVAL(0)))(quantity<TestType>));
}

