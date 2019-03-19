// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/si/all.hpp>
#include <dimensional/prefix.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/delta.hpp>
#include <dimensional/derived_units/dgree_celsius.hpp>
#include "test_util.hpp"

using mitama::delta, mitama::si::meter_t, mitama::si::ampere_t, mitama::si::candela_t, mitama::si::kelvin_t, mitama::si::kilogram_t, mitama::si::mol_t, mitama::si::second_t;

TEMPLATE_TEST_CASE("delta construct",
                   "[delta][constructor]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    delta d = (2|TestType{}) - (1|TestType{});
    REQUIRE(d.get() == (1|TestType{}));
}

TEMPLATE_TEST_CASE("delta addition",
                   "[delta][constructor]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    delta d = (2|TestType{}) - (1|TestType{});
    REQUIRE(d + (2|TestType{}) == (3|TestType{}));
    REQUIRE((2|TestType{}) + d == (3|TestType{}));
    REQUIRE(d + d == (2|TestType{}));
}

TEMPLATE_TEST_CASE("delta subtraction",
                   "[delta][constructor]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    delta d = (2|TestType{}) - (1|TestType{});
    REQUIRE(d - (2|TestType{}) == (-1|TestType{}));
    REQUIRE((2|TestType{}) - d == (1|TestType{}));
    REQUIRE(d - d == (0|TestType{}));
}

TEMPLATE_TEST_CASE("delta multiplication",
                   "[delta][constructor]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    delta d = (2|TestType{}) - (1|TestType{});
    REQUIRE((d * (2|TestType{})) == (2|TestType{}*TestType{}));
    REQUIRE((2|TestType{}) * d == (2|TestType{}*TestType{}));
    REQUIRE(d * d == (1|TestType{}*TestType{}));
}

TEMPLATE_TEST_CASE("delta division",
                   "[delta][constructor]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    delta d = (2|TestType{}) - (1|TestType{});
    REQUIRE((d / (1|TestType{})) == (1|TestType{}/TestType{}));
    REQUIRE((2|TestType{}) / d == (2|TestType{}/TestType{}));
    REQUIRE(d / d == (1|TestType{}/TestType{}));
}

TEST_CASE("delta temperature",
                   "[delta][constructor]")
{
    using mitama::si::kelvins, mitama::delta, mitama::nonsi::dgree_celsius;
    {
        delta d = (2|dgree_celsius) - (1|dgree_celsius);
        REQUIRE((1|kelvins) + d == (2|kelvins));
    }
    {
        delta d = (2|kelvins) - (1|kelvins);
        REQUIRE((1|dgree_celsius) + d == (2|dgree_celsius));
    }
}

