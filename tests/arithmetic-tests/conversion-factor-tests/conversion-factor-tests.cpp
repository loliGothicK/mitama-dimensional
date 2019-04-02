#include "../config.hpp"
TEMPLATE_TEST_CASE("conversion-factor-tests",
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

