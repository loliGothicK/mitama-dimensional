// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/si/all.hpp>
#include <dimensional/prefix.hpp>
#include <dimensional/arithmetic.hpp>
#include "test_util.hpp"

using mitama::si::meter_t, mitama::si::ampere_t, mitama::si::candela_t, mitama::si::kelvin_t, mitama::si::kilogram_t, mitama::si::mol_t, mitama::si::second_t;

TEMPLATE_TEST_CASE("delta construct",
                   "[delta][constructor]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using mitama::si::meters, mitama::delta;
    delta d = (2|meters) - (1|meters);
    REQUIRE(d.get() == (1|meters));
}

