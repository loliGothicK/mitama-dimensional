#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include <quantity.hpp>
#include <si/all.hpp>
#define CAT(A, B)
#define PAEAMETERIZED_TEST_CLASS(NAME) \
    template <class T> struct NAME {\
        using quantity_type = ::mitama::quantity<::mitama:: ## NAME ## _t, T>;\
        using value_type = T;\
    }

namespace gen {
    PAEAMETERIZED_TEST_CLASS(ampere);
    PAEAMETERIZED_TEST_CLASS(meter);
    PAEAMETERIZED_TEST_CLASS(candela);
    PAEAMETERIZED_TEST_CLASS(kelvin);
    PAEAMETERIZED_TEST_CLASS(kilogram);
    PAEAMETERIZED_TEST_CLASS(mol);
    PAEAMETERIZED_TEST_CLASS(second);
    PAEAMETERIZED_TEST_CLASS(meter);
    PAEAMETERIZED_TEST_CLASS(meter);
}

TEMPLATE_PRODUCT_TEST_CASE("constructor",
                           "[quantity]",
                           (gen::meter, gen::ampere, gen::candela, gen::kelvin, gen::kilogram, gen::mol, gen::second),
                           (int, long, long long, float, double))
{
    using quantity_type = typename TestType::quantity_type;
    using value_type = typename TestType::value_type;

    quantity_type quant(value_type{});
    REQUIRE( quant.get() == value_type{} );
}