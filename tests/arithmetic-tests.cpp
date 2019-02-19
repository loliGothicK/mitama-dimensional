// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <quantity.hpp>
#include <si/all.hpp>
#include <prefix.hpp>
#include <arithmetic.hpp>
#include "test_util.hpp"

using namespace mitama;

TEMPLATE_TEST_CASE("arithmetic for same dimension",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    quantity<TestType, int> a = 1;
    quantity<TestType, int> b = 1;
    SECTION( "same scale" ) {
        REQUIRE( (a + b).get() == 2 );
        REQUIRE( (a - b).get() == 0 );
    }
    SECTION( "different scale" ) {
        quantity<scaled_unit_t<TestType, std::milli>, int> c = 1;
        quantity<scaled_unit_t<TestType, std::kilo>, int> d = 1;
        REQUIRE( (c + b).get() == 1'001 );
        REQUIRE( (a - c).get() == 999 );
        REQUIRE( (b + d).get() == 1'001 );
        REQUIRE( (b - d).get() == -999 );
        REQUIRE( (c + d).get() == 1'000'001 );
        REQUIRE( (d - c).get() == 999'999 );
    }
}

TEMPLATE_TEST_CASE("meter_t addition and subtraction negative tests",
                   "[quantity][arithmetic]",
                   ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(meter_t, TestType) );
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(meter_t, TestType) );
}

TEMPLATE_TEST_CASE("ampere_t addition and subtraction negative tests",
                   "[quantity][arithmetic]",
                   meter_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(ampere_t, TestType) );
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(ampere_t, TestType) );
}

TEMPLATE_TEST_CASE("candela_t addition and subtraction negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(candela_t, TestType) );
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(candela_t, TestType) );
}

TEMPLATE_TEST_CASE("kelvin_t addition and subtraction negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kilogram_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(kelvin_t, TestType) );
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(kelvin_t, TestType) );
}

TEMPLATE_TEST_CASE("kilogram_t addition and subtraction negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, mol_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(kilogram_t, TestType) );
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(kilogram_t, TestType) );
}

TEMPLATE_TEST_CASE("mol_t addition and subtraction negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, second_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(mol_t, TestType) );
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(mol_t, TestType) );
}

TEMPLATE_TEST_CASE("second_t addition and subtraction negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) + DECLVAL(1))(second_t, TestType) );
    REQUIRE( IS_INVALID_EXPR(DECLVAL(0) - DECLVAL(1))(second_t, TestType) );
}

TEMPLATE_TEST_CASE("meter_t multiply",
                   "[quantity][arithmetic]",
                   ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    quantity<meter_t, int> a = 2;
    quantity<TestType, int> b = 3;
    REQUIRE( (a * b).get() == 6 );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a*b)>,
        quantity_t<dimensional_t<
            units_t<length, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<1>, std::ratio<1>>
        >, int>>);
}

TEMPLATE_TEST_CASE("ampere_t multiply",
                   "[quantity][arithmetic]",
                   meter_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    quantity<ampere_t, int> a = 2;
    quantity<TestType, int> b = 3;
    REQUIRE( (a * b).get() == 6 );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a*b)>,
        quantity_t<dimensional_t<
            units_t<electric_current, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<1>, std::ratio<1>>
        >, int>>);
}

TEMPLATE_TEST_CASE("candela_t multiply",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    quantity<candela_t, int> a = 2;
    quantity<TestType, int> b = 3;
    REQUIRE( (a * b).get() == 6 );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a*b)>,
        quantity_t<dimensional_t<
            units_t<luminous_intensity, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<1>, std::ratio<1>>
        >, int>>);
}

TEMPLATE_TEST_CASE("kelvin_t multiply",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kilogram_t, mol_t, second_t)
{
    quantity<kelvin_t, int> a = 2;
    quantity<TestType, int> b = 3;
    REQUIRE( (a * b).get() == 6 );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a*b)>,
        quantity_t<dimensional_t<
            units_t<thermodynamic_temperature, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<1>, std::ratio<1>>
        >, int>>);
}

TEMPLATE_TEST_CASE("kilogram_t multiply",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, mol_t, second_t)
{
    quantity<kilogram_t, int> a = 2;
    quantity<TestType, int> b = 3;
    REQUIRE( (a * b).get() == 6 );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a*b)>,
        quantity_t<dimensional_t<
            units_t<mass, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<1>, std::ratio<1>>
        >, int>>);
}

TEMPLATE_TEST_CASE("mol_t multiply",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, second_t)
{
    quantity<mol_t, int> a = 2;
    quantity<TestType, int> b = 3;
    REQUIRE( (a * b).get() == 6 );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a*b)>,
        quantity_t<dimensional_t<
            units_t<amount_of_substance, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<1>, std::ratio<1>>
        >, int>>);
}

TEMPLATE_TEST_CASE("second_t multiply",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    quantity<second_t, int> a = 2;
    quantity<TestType, int> b = 3;
    REQUIRE( (a * b).get() == 6 );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a*b)>,
        quantity_t<dimensional_t<
            units_t<mitama::time, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<1>, std::ratio<1>>
        >, int>>);
}

TEMPLATE_TEST_CASE("meter_t division",
                   "[quantity][arithmetic]",
                   ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    quantity<meter_t, double> a = 2;
    quantity<TestType, double> b = 10;
    REQUIRE( (a / b).get() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<dimensional_t<
            units_t<length, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >, double>>);
}

TEMPLATE_TEST_CASE("ampere_t division",
                   "[quantity][arithmetic]",
                   meter_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    quantity<ampere_t, double> a = 2;
    quantity<TestType, double> b = 10;
    REQUIRE( (a / b).get() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<dimensional_t<
            units_t<electric_current, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >, double>>);
}

TEMPLATE_TEST_CASE("candela_t division",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    quantity<candela_t, double> a = 2;
    quantity<TestType, double> b = 10;
    REQUIRE( (a / b).get() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<dimensional_t<
            units_t<luminous_intensity, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >, double>>);
}

TEMPLATE_TEST_CASE("kelvin_t division",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    quantity<kelvin_t, double> a = 2;
    quantity<TestType, double> b = 10;
    REQUIRE( (a / b).get() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<dimensional_t<
            units_t<thermodynamic_temperature, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >, double>>);
}

TEMPLATE_TEST_CASE("kilogram_t division",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, mol_t, second_t)
{
    using namespace Catch::literals;
    quantity<kilogram_t, double> a = 2;
    quantity<TestType, double> b = 10;
    REQUIRE( (a / b).get() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<dimensional_t<
            units_t<mass, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >, double>>);
}

TEMPLATE_TEST_CASE("mol_t division",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, second_t)
{
    using namespace Catch::literals;
    quantity<mol_t, double> a = 2;
    quantity<TestType, double> b = 10;
    REQUIRE( (a / b).get() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<dimensional_t<
            units_t<amount_of_substance, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >, double>>);
}

TEMPLATE_TEST_CASE("second_t division",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;
    quantity<second_t, double> a = 2;
    quantity<TestType, double> b = 10;
    REQUIRE( (a / b).get() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<dimensional_t<
            units_t<mitama::time, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >, double>>);
}

