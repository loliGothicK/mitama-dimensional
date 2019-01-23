// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <quantity.hpp>
#include <si/all.hpp>

using namespace mitama;

TEMPLATE_TEST_CASE("constructor",
                   "[quantity]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    quantity<TestType, int> quant(0);
    REQUIRE( quant.get() == 0 );
}