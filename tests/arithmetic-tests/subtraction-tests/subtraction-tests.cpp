#include "../config.hpp"
TEMPLATE_TEST_CASE("meter_t subtraction negative tests",
                   "[quantity][arithmetic]",
                   ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(meter_t, TestType) );
}

TEMPLATE_TEST_CASE("ampere_t subtraction negative tests",
                   "[quantity][arithmetic]",
                   meter_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(ampere_t, TestType) );
}

TEMPLATE_TEST_CASE("candela_t subtraction negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(candela_t, TestType) );
}

TEMPLATE_TEST_CASE("kelvin_t subtraction negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(kelvin_t, TestType) );
}

TEMPLATE_TEST_CASE("kilogram_t subtraction negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(kilogram_t, TestType) );
}

TEMPLATE_TEST_CASE("mol_t subtraction negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(mol_t, TestType) );
}

TEMPLATE_TEST_CASE("second_t subtraction negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(second_t, TestType) );
}

