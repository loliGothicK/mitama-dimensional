#include "../config.hpp"
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
            units_t<mitama::si::time, std::ratio<1>, std::ratio<1>>,
            units_t<typename basis_<TestType>::template type<0>, std::ratio<1>, std::ratio<1>>
        >, int>>);
}

