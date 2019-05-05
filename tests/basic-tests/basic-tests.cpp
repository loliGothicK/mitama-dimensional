// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/prefix.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/refinement.hpp>
#include <dimensional/nonsi_units/minute.hpp>
#include <dimensional/nonsi_units/hour.hpp>
#include <dimensional/nonsi_units/day.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEMPLATE_TEST_CASE("constructor from values",
                   "[quantity][constructor]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    quantity<TestType, int> a(1);
    REQUIRE( a.value() == 1 );

    quantity<scaled_unit_t<TestType, std::milli>, double> b = a;
    REQUIRE( b.value() == 1000 );
}

TEMPLATE_TEST_CASE("meter_t from other quantities",
                   "[quantity][constructor]",
                   ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLTYPE(0){DECLVAL(1)})(meter_t, TestType) );
}

TEMPLATE_TEST_CASE("ampere_t from other quantities",
                   "[quantity][constructor]",
                   meter_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLTYPE(0){DECLVAL(1)})(ampere_t, TestType) );
}

TEMPLATE_TEST_CASE("candela_t from other quantities",
                   "[quantity][constructor]",
                   meter_t, ampere_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLTYPE(0){DECLVAL(1)})(candela_t, TestType) );
}

TEMPLATE_TEST_CASE("kelvin_t from other quantities",
                   "[quantity][constructor]",
                   meter_t, ampere_t, candela_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLTYPE(0){DECLVAL(1)})(kelvin_t, TestType) );
}

TEMPLATE_TEST_CASE("kilogram_t from other quantities",
                   "[quantity][constructor]",
                   meter_t, ampere_t, candela_t, kelvin_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLTYPE(0){DECLVAL(1)})(kilogram_t, TestType) );
}

TEMPLATE_TEST_CASE("mol_t from other quantities",
                   "[quantity][constructor]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLTYPE(0){DECLVAL(1)})(mol_t, TestType) );
}

TEMPLATE_TEST_CASE("second_t from other quantities",
                   "[quantity][constructor]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLTYPE(0){DECLVAL(1)})(second_t, TestType) );
}

TEMPLATE_TEST_CASE("validates",
                   "[quantity][validate]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    auto validator = [](auto v) -> mitama::Result<quantity<TestType, int>, int> {
        if (v.value() < 0)
            return mitama::Err(v.value());
        else
            return mitama::Ok(v);
    };

    REQUIRE( (1|TestType{}).validate(validator) == Ok(1|TestType{}) );
    REQUIRE( (-1|TestType{}).validate(validator) == Err(-1) );
}

TEMPLATE_TEST_CASE("refinement T^1 negative",
                   "[quantity][refinement]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    REQUIRE( IS_INVALID_EXPR( exact_for<sym::T<1>> |= quantity<DECLTYPE(0)>{} )(TestType) );
}

TEMPLATE_TEST_CASE("refinement L^1 negative",
                   "[quantity][refinement]",
                   second_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    REQUIRE( IS_INVALID_EXPR( exact_for<sym::L<1>> |= quantity<DECLTYPE(0)>{} )(TestType) );
}

TEMPLATE_TEST_CASE("refinement M^1 negative",
                   "[quantity][refinement]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, mol_t)
{
    REQUIRE( IS_INVALID_EXPR( exact_for<sym::M<1>> |= quantity<DECLTYPE(0)>{} )(TestType) );
}

TEMPLATE_TEST_CASE("refinement I^1 negative",
                   "[quantity][refinement]",
                   second_t, meter_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    REQUIRE( IS_INVALID_EXPR( exact_for<sym::I<1>> |= quantity<DECLTYPE(0)>{} )(TestType) );
}

TEMPLATE_TEST_CASE("refinement S^1 negative",
                   "[quantity][refinement]",
                   second_t, meter_t, ampere_t, candela_t, kilogram_t, mol_t)
{
    REQUIRE( IS_INVALID_EXPR( exact_for<sym::S<1>> |= quantity<DECLTYPE(0)>{} )(TestType) );
}

TEMPLATE_TEST_CASE("refinement N^1 negative",
                   "[quantity][refinement]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t)
{
    REQUIRE( IS_INVALID_EXPR( exact_for<sym::N<1>> |= quantity<DECLTYPE(0)>{} )(TestType) );
}

TEMPLATE_TEST_CASE("refinement J^1 negative",
                   "[quantity][refinement]",
                   second_t, meter_t, ampere_t, kelvin_t, kilogram_t, mol_t)
{
    REQUIRE( IS_INVALID_EXPR( exact_for<sym::J<1>> |= quantity<DECLTYPE(0)>{} )(TestType) );
}

TEMPLATE_TEST_CASE("refinement L^1 positive",
                   "[quantity][refinement]",
                   picometer_t, nanometer_t, micrometer_t, millimeter_t, centimeter_t, decimeter_t, kilometer_t, megameter_t)
{
    REQUIRE( !IS_INVALID_EXPR( exact_for<sym::L<1>> |= quantity<DECLTYPE(0)>{} )(TestType) );
}

TEMPLATE_TEST_CASE("refinement L^1 positive",
                   "[quantity][refinement]",
                   second_t, millisecond_t, microsecond_t, nanosecond_t, nonsi::minute_t, nonsi::hour_t, nonsi::day_t)
{
    REQUIRE( !IS_INVALID_EXPR( exact_for<sym::T<1>> |= quantity<DECLTYPE(0)>{} )(TestType) );
}

TEMPLATE_TEST_CASE("refinement I^1 positive",
                   "[quantity][refinement]",
                   ampere_t, milliampere_t, microampere_t, nanoampere_t, kiloampere_t, megaampere_t)
{
    REQUIRE( !IS_INVALID_EXPR( exact_for<sym::I<1>> |= quantity<DECLTYPE(0)>{} )(TestType) );
}

TEMPLATE_TEST_CASE("refinement S^1 positive",
                   "[quantity][refinement]",
                   kelvin_t, millikelvin_t)
{
    REQUIRE( !IS_INVALID_EXPR( exact_for<sym::S<1>> |= quantity<DECLTYPE(0)>{} )(TestType) );
}

TEMPLATE_TEST_CASE("refinement N^1 positive",
                   "[quantity][refinement]",
                   micromol_t, millimol_t, mol_t, kilomol_t)
{
    REQUIRE( !IS_INVALID_EXPR( exact_for<sym::N<1>> |= quantity<DECLTYPE(0)>{} )(TestType) );
}

TEMPLATE_TEST_CASE("refinement J^1 positive",
                   "[quantity][refinement]",
                   candela_t)
{
    REQUIRE( !IS_INVALID_EXPR( exact_for<sym::J<1>> |= quantity<DECLTYPE(0)>{} )(TestType) );
}

