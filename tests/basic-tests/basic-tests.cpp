// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/systems/si/prefix.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include <mitama/dimensional/arithmetic.hpp>

#include <test_util.hpp>

using namespace mitama;
namespace si = mitama::systems::si;
namespace nonsi = mitama::systems::nonsi;

TEMPLATE_TEST_CASE("constructor from values",
                   "[quantity][constructor]",
                   si::meter_t, si::ampere_t, si::candela_t, si::kelvin_t, si::kilogram_t, si::mol_t, si::second_t)
{
    si::quantity_t<TestType, int> a(1);
    REQUIRE( a == (1|TestType{}) );

    si::quantity_t<scaled_unit_t<TestType, std::milli>, double> b = a;
    REQUIRE( b.value() == 1000 );
}

TEMPLATE_TEST_CASE("validates",
                   "[quantity][validate]",
                   si::meter_t, si::ampere_t, si::candela_t, si::kelvin_t, si::kilogram_t, si::mol_t, si::second_t)
{
    auto validator = [](auto v) -> mitama::result<si::quantity_t<TestType, int>, int> {
        if (v.value() < 0)
            return mitama::failure(v.value());
        else
            return mitama::success(v);
    };

    REQUIRE( (1|TestType{}).validate(validator) == mitama::success(1|TestType{}) );
    REQUIRE( (-1|TestType{}).validate(validator) == mitama::failure(-1) );
}

#include <mitama/dimensional/systems/si/quantity.hpp>

TEMPLATE_TEST_CASE("si-quantity; constructor from values","[quantity][constructor]",
                   si::meter_t, si::ampere_t, si::candela_t, si::kelvin_t, si::kilogram_t, si::mol_t, si::second_t)
{
  systems::si::quantity_t<TestType, int> a(1);
  REQUIRE(a.value() == 1);

  systems::si::quantity_t<scaled_unit_t<TestType, std::milli>, double> b = a;
  REQUIRE(b.value() == 1000);
}
