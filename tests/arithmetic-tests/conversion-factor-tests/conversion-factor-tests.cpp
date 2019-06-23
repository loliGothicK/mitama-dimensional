#include "../config.hpp"
TEMPLATE_TEST_CASE("conversion-factor-tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    quantity_t<TestType, int> a = 1;
    quantity_t<TestType, int> b = 1;
    SECTION( "same scale" ) {
        REQUIRE( (a + b).value() == 2 );
        REQUIRE( (a - b).value() == 0 );
    }
    SECTION( "different scale" ) {
        quantity_t<scaled_unit_t<TestType, std::milli>, int> c = 1;
        quantity_t<scaled_unit_t<TestType, std::kilo>, int> d = 1;
        REQUIRE( (c + b).value() == 1'001 );
        REQUIRE( (a - c).value() == 999 );
        REQUIRE( (b + d).value() == 1'001 );
        REQUIRE( (b - d).value() == -999 );
        REQUIRE( (c + d).value() == 1'000'001 );
        REQUIRE( (d - c).value() == 999'999 );
    }
}

