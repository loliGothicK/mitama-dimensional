#include "../config.hpp"
#include <boost/type_index.hpp>
TEMPLATE_TEST_CASE("meter_t addition negative tests",
                   "[quantity][arithmetic]",
                   ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(meter_t, TestType) );
}

TEMPLATE_TEST_CASE("ampere_t addition negative tests",
                   "[quantity][arithmetic]",
                   meter_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(ampere_t, TestType) );
}

TEMPLATE_TEST_CASE("candela_t addition negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(candela_t, TestType) );
}

TEMPLATE_TEST_CASE("kelvin_t addition negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(kelvin_t, TestType) );
}

TEMPLATE_TEST_CASE("kilogram_t addition negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(kilogram_t, TestType) );
}

TEMPLATE_TEST_CASE("mol_t addition negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(mol_t, TestType) );
}

TEMPLATE_TEST_CASE("second_t addition negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(second_t, TestType) );
}

TEMPLATE_TEST_CASE("add quantity and value tests",
                   "[quantity][arithmetic]",
                   int, unsigned, double, float, long long, long double)
{
    REQUIRE( std::is_same_v<std::decay_t<decltype(std::declval<TestType>() + std::declval<quantity_t<dimless_t, TestType>>())>, TestType> );
}

