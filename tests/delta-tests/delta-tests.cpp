// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/prefix.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/delta.hpp>
#include <dimensional/systems/nonsi/degree_celsius.hpp>
#include <test_util.hpp>

using mitama::delta, mitama::systems::si::meter_t, mitama::systems::si::ampere_t, mitama::systems::si::candela_t, mitama::systems::si::kelvin_t, mitama::systems::si::kilogram_t, mitama::systems::si::mol_t, mitama::systems::si::second_t;

TEMPLATE_TEST_CASE("delta construct",
                   "[delta][constructor]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    delta d = (2|TestType{}) - (1|TestType{});
    REQUIRE(d.value() == (1|TestType{}));
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
    using mitama::systems::si::kelvins, mitama::delta, mitama::systems::nonsi::degree_celsius;
    {
        delta d = (2|degree_celsius) - (1|degree_celsius);
        REQUIRE((1|kelvins) + d == (2|kelvins));
    }
    {
        delta d = (2|kelvins) - (1|kelvins);
        REQUIRE((1|degree_celsius) + d == (2|degree_celsius));
    }
}

