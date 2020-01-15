// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/prefix.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/refinement.hpp>
#include <dimensional/systems/nonsi/minute.hpp>
#include <dimensional/systems/nonsi/hour.hpp>
#include <dimensional/systems/nonsi/day.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;
using namespace mitama::systems::nonsi;

TEMPLATE_TEST_CASE("constructor from values",
                   "[quantity][constructor]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    quantity_t<TestType, int> a(1);
    REQUIRE( a.value() == 1 );

    quantity_t<scaled_unit_t<TestType, std::milli>, double> b = a;
    REQUIRE( b.value() == 1000 );
}

TEMPLATE_TEST_CASE("validates",
                   "[quantity][validate]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    auto validator = [](auto v) -> mitama::result<quantity_t<TestType, int>, int> {
        if (v.value() < 0)
            return mitama::failure(v.value());
        else
            return mitama::success(v);
    };

    REQUIRE( (1|TestType{}).validate(validator) == success(1|TestType{}) );
    REQUIRE( (-1|TestType{}).validate(validator) == failure(-1) );
}

#include <dimensional/systems/si/quantity.hpp>

TEMPLATE_TEST_CASE("si-quantity; constructor from values","[quantity][constructor]",
  meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
  systems::si::quantity_t<TestType, int> a(1);
  REQUIRE(a.value() == 1);

  systems::si::quantity_t<scaled_unit_t<TestType, std::milli>, double> b = a;
  REQUIRE(b.value() == 1000);
}
