#include "../config.hpp"
TEMPLATE_TEST_CASE("meter_t division",
                   "[quantity][arithmetic]",
                   ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    quantity_t<meter_t, double> a = 2;
    quantity_t<TestType, double> b = 10;
    REQUIRE( (a / b).value() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<si_base_units<dimensional_t<
            units_t<0, length, std::ratio<1>, std::ratio<1>>,
            units_t<0, typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >>, double>>);
}

TEMPLATE_TEST_CASE("ampere_t division",
                   "[quantity][arithmetic]",
                   meter_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    quantity_t<ampere_t, double> a = 2;
    quantity_t<TestType, double> b = 10;
    REQUIRE( (a / b).value() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<si_base_units<dimensional_t<
            units_t<0, electric_current, std::ratio<1>, std::ratio<1>>,
            units_t<0, typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >>, double>>);
}

TEMPLATE_TEST_CASE("candela_t division",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    quantity_t<candela_t, double> a = 2;
    quantity_t<TestType, double> b = 10;
    REQUIRE( (a / b).value() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<si_base_units<dimensional_t<
            units_t<0, luminous_intensity, std::ratio<1>, std::ratio<1>>,
            units_t<0, typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >>, double>>);
}

TEMPLATE_TEST_CASE("kelvin_t division",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    quantity_t<kelvin_t, double> a = 2;
    quantity_t<TestType, double> b = 10;
    REQUIRE( (a / b).value() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<si_base_units<dimensional_t<
            units_t<0, thermodynamic_temperature, std::ratio<1>, std::ratio<1>>,
            units_t<0, typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >>, double>>);
}

TEMPLATE_TEST_CASE("kilogram_t division",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, mol_t, second_t)
{
    using namespace Catch::literals;
    quantity_t<kilogram_t, double> a = 2;
    quantity_t<TestType, double> b = 10;
    REQUIRE( (a / b).value() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<si_base_units<dimensional_t<
            units_t<0, mass, std::ratio<1>, std::ratio<1>>,
            units_t<0, typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >>, double>>);
}

TEMPLATE_TEST_CASE("mol_t division",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, second_t)
{
    using namespace Catch::literals;
    quantity_t<mol_t, double> a = 2;
    quantity_t<TestType, double> b = 10;
    REQUIRE( (a / b).value() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<si_base_units<dimensional_t<
            units_t<0, amount_of_substance, std::ratio<1>, std::ratio<1>>,
            units_t<0, typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >>, double>>);
}

TEMPLATE_TEST_CASE("second_t division",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;
    quantity_t<second_t, double> a = 2;
    quantity_t<TestType, double> b = 10;
    REQUIRE( (a / b).value() == 0.2_a );
    REQUIRE(
        std::is_same_v<std::decay_t<decltype(a/b)>,
        quantity_t<si_base_units<dimensional_t<
            units_t<0, mitama::systems::si::time, std::ratio<1>, std::ratio<1>>,
            units_t<0, typename basis_<TestType>::template type<0>, std::ratio<-1>, std::ratio<1>>
        >>, double>>);
}

