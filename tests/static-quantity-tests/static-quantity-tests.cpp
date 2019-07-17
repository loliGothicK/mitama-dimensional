// main is provided in tests-main.cpp
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/static_quantity.hpp>
#include <mitama/dimensional/systems/si/base_units/meter.hpp>
#include <mitama/dimensional/io.hpp>
#include <iostream>
#include <catch2/catch.hpp>

template < auto Arg >
struct is_even: std::bool_constant<Arg % 2 == 0> {};

template < auto Arg >
struct is_odd: std::bool_constant<Arg % 2 == 1> {};

namespace si = mitama::systems::si;
using mitama::static_quantity, mitama::refined, mitama::quantity_t;
using namespace mitama::literals::static_quantity_literals;

TEMPLATE_TEST_CASE("static-quantity instantiation",
                   "[static-quantity]",
                   si::meter_t, si::kilogram_t, si::ampere_t, si::candela_t, si::second_t, si::mol_t, si::kelvin_t)
{
    REQUIRE(std::decay_t<decltype(static_quantity<TestType, 1>)>::value == 1);
    REQUIRE(std::decay_t<decltype(static_quantity<TestType, -1>)>::value == -1);
}

TEMPLATE_TEST_CASE("static-quantity underlying type",
                   "[static-quantity]",
                   short, int, long, long long, unsigned, unsigned long, unsigned long long)
{
    REQUIRE(std::is_same_v<typename std::decay_t<decltype(static_quantity<si::meter_t, TestType{}>)>::value_type, TestType>);
}

TEST_CASE("static-quantity literals",
          "[static-quantity]")
{
    REQUIRE(get(1_m) == 1);
    REQUIRE(get(1_mm) == 1);
    REQUIRE(get(1_km) == 1);

    REQUIRE(get(1_s) == 1);
    REQUIRE(get(1_ms) == 1);
    REQUIRE(get(1_us) == 1);
    REQUIRE(get(1_ns) == 1);

    REQUIRE(get(1_mA) == 1);
    REQUIRE(get(1_A) == 1);
    REQUIRE(get(1_kA) == 1);

    REQUIRE(get(1_mg) == 1);
    REQUIRE(get(1_g) == 1);
    REQUIRE(get(1_kg) == 1);

    REQUIRE(get(1_K) == 1);
    REQUIRE(get(1_mK) == 1);

    REQUIRE(get(1_mol) == 1);
    REQUIRE(get(1_mmol) == 1);

    REQUIRE(get(1_cd) == 1);
}

TEMPLATE_TEST_CASE("static-quantity refinement",
                   "[static-quantity]",
                   si::meter_t, si::kilogram_t, si::ampere_t, si::candela_t, si::second_t, si::mol_t, si::kelvin_t)
{
    REQUIRE(refined<is_even, quantity_t<TestType, int>>(static_quantity<TestType, 2>).get() == quantity_t<TestType, int>(2));
}

TEMPLATE_TEST_CASE("static-quantity negation",
                   "[static-quantity]",
                   si::meter_t, si::kilogram_t, si::ampere_t, si::candela_t, si::second_t, si::mol_t, si::kelvin_t)
{
    constexpr auto _1 = static_quantity<TestType, 2>;
    REQUIRE(get(_1) == 2);
    constexpr auto _2 = -_1;
    REQUIRE(get(_2) == -2);
    constexpr auto _3 = -_2;
    REQUIRE(get(_3) == 2);
}
