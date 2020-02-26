// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include <mitama/dimensional/arithmetic.hpp>
#include <mitama/dimensional/systems/si/prefix.hpp>
#include <test_util.hpp>

using namespace mitama;
namespace si = mitama::systems::si;

TEMPLATE_TEST_CASE("equal",
                   "[quantity][relationals]",
                   si::meter_t, si::ampere_t, si::candela_t, si::kelvin_t, si::kilogram_t, si::mol_t, si::second_t)
{
    si::quantity_t<TestType, int> a(1);
    si::quantity_t<TestType, int> b(1);
    si::quantity_t<TestType, int> c(2);
    REQUIRE( a == a );
    REQUIRE( a == b );
    REQUIRE( b == a );
    REQUIRE_FALSE( a == c );
    REQUIRE_FALSE( c == a );
    REQUIRE( a + b == c );
    REQUIRE( c - a == b );
    REQUIRE( (a * c).value() == c.value() );
    REQUIRE( (c / b).value() == c.value() );
}

TEMPLATE_TEST_CASE("equal with different scales",
                   "[quantity][relationals]",
                   si::meter_t, si::ampere_t, si::candela_t, si::kelvin_t, si::kilogram_t, si::mol_t, si::second_t)
{
    si::quantity_t<decltype(si::milli * TestType{}), int> a(1);
    si::quantity_t<decltype(si::milli * TestType{}), int> b(1000);
    si::quantity_t<TestType, int> c(1);
    REQUIRE_FALSE( a == b );
    REQUIRE_FALSE( b == a );
    REQUIRE( b == c );
    REQUIRE( c == b );
}

TEMPLATE_TEST_CASE("less",
                   "[quantity][relationals]",
                   si::meter_t, si::ampere_t, si::candela_t, si::kelvin_t, si::kilogram_t, si::mol_t, si::second_t)
{
    si::quantity_t<TestType, int> a(1);
    si::quantity_t<TestType, int> b(2);
    REQUIRE( a < b );
    REQUIRE_FALSE( a < a );
    REQUIRE_FALSE( b < a );
}

TEMPLATE_TEST_CASE("less with different scales",
                   "[quantity][relationals]",
                   si::meter_t, si::ampere_t, si::candela_t, si::kelvin_t, si::kilogram_t, si::mol_t, si::second_t)
{
    si::quantity_t<decltype(si::milli * TestType{}), int> a(1);
    si::quantity_t<TestType, int> b(1);
    REQUIRE( a < b );
    REQUIRE_FALSE( b < a );
}

TEMPLATE_TEST_CASE("greater",
                   "[quantity][relationals]",
                   si::meter_t, si::ampere_t, si::candela_t, si::kelvin_t, si::kilogram_t, si::mol_t, si::second_t)
{
    si::quantity_t<TestType, int> a(1);
    si::quantity_t<TestType, int> b(2);
    REQUIRE_FALSE( a > b );
    REQUIRE_FALSE( a > a );
    REQUIRE( b > a );
}

TEMPLATE_TEST_CASE("greater with different scales",
                   "[quantity][relationals]",
                   si::meter_t, si::ampere_t, si::candela_t, si::kelvin_t, si::kilogram_t, si::mol_t, si::second_t)
{
    si::quantity_t<decltype(si::milli * TestType{}), int> a(1);
    si::quantity_t<TestType, int> b(1);
    REQUIRE_FALSE( a > b );
    REQUIRE( b > a );
}

TEMPLATE_TEST_CASE("less or equal",
                   "[quantity][relationals]",
                   si::meter_t, si::ampere_t, si::candela_t, si::kelvin_t, si::kilogram_t, si::mol_t, si::second_t)
{
    si::quantity_t<TestType, int> a(1);
    si::quantity_t<TestType, int> b(2);
    REQUIRE( a <= b );
    REQUIRE( a <= a );
    REQUIRE_FALSE( b <= a );
}

TEMPLATE_TEST_CASE("less or equal with different scales",
                   "[quantity][relationals]",
                   si::meter_t, si::ampere_t, si::candela_t, si::kelvin_t, si::kilogram_t, si::mol_t, si::second_t)
{
    si::quantity_t<decltype(si::milli * TestType{}), int> a(1);
    si::quantity_t<TestType, int> b(1);
    REQUIRE( a <= b );
    REQUIRE_FALSE( b <= a );
}

TEMPLATE_TEST_CASE("greater or equal",
                   "[quantity][relationals]",
                   si::meter_t, si::ampere_t, si::candela_t, si::kelvin_t, si::kilogram_t, si::mol_t, si::second_t)
{
    si::quantity_t<TestType, int> a(1);
    si::quantity_t<TestType, int> b(2);
    REQUIRE_FALSE( a >= b );
    REQUIRE( a >= a );
    REQUIRE( b >= a );
}

TEMPLATE_TEST_CASE("greater or equal with different scales",
                   "[quantity][relationals]",
                   si::meter_t, si::ampere_t, si::candela_t, si::kelvin_t, si::kilogram_t, si::mol_t, si::second_t)
{
    si::quantity_t<decltype(si::milli * TestType{}), int> a(1);
    si::quantity_t<TestType, int> b(1);
    REQUIRE_FALSE( a >= b );
    REQUIRE( b >= a );
}
