// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/si/all.hpp>
#include <dimensional/prefix.hpp>
#include "test_util.hpp"

using namespace mitama;

TEMPLATE_TEST_CASE("constructor from values",
                   "[quantity][constructor]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    quantity<TestType, int> a(1);
    REQUIRE( a.get() == 1 );

    quantity<scaled_unit_t<TestType, std::milli>, double> b = a;
    REQUIRE( b.get() == 1000 );
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
        if (v.get() < 0)
            return mitama::Err(v.get());
        else
            return mitama::Ok(v);
    };

    REQUIRE( (1|TestType{}).validate(validator) == Ok(1|TestType{}) );
    REQUIRE( (-1|TestType{}).validate(validator) == Err(-1) );
}