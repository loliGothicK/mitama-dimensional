#include "../include/dimensional/quantity.hpp"
#include "../include/dimensional/arithmetic.hpp"
#include "../include/dimensional/si/meter.hpp"
#include "../include/dimensional/si/second.hpp"
#include "../include/dimensional/io.hpp"
#include "../include/dimensional/refinement.hpp"
#include "../include/dimensional/prefix.hpp"
#include "../include/dimensional/math/all.hpp"
#include "../include/dimensional/currency/jpy.hpp"
#include "../include/dimensional/derived_units/dgree_celsius.hpp"
#include "../include/dimensional/expr.hpp"
#include <boost/type_index.hpp>
#include <iostream>


#define REPL(...) \
    do { std::cout << "$ " << #__VA_ARGS__ << "\n=> " << (__VA_ARGS__) << std::endl; } while(false)
int main(){
    using namespace mitama;
    { // Homogeneous dimension examples
        std::cout << "--[Homogeneous dimension examples]--\n";

        // quantity<Dimension, Type = double>:
        // quantity is the type T that is meaningful by Dimension;
        // Dimension is a phantom template parameter.
        constexpr quantity<si::meter_t, int> a = 2;
        constexpr quantity<si::millimeter_t, int> b = 2;
        
        // `a + b` is valid operation if and only if `a` and `b` has same base dimensions.
        auto r1 = a + b;
        REPL(r1);
        
        // `a - b` is valid operation if and only if `a` and `b` has same base dimensions.
        auto r2 = a - b;
        REPL(r2);
        
        // `a * b` is always valid and:
        // - Result quantity has heterogeneous dimension inducted from `a` and `b`, and
        // - If both a and b values are of the same dimension, these values are automatically scaled to high precision units.
        auto r3 = a * b;
        REPL(r3);

        // a / b := a * b^{-1}
        auto r4 = a / b;
        REPL(r4);
        REPL(boost::typeindex::type_id<decltype(r4)>().pretty_name());

        quantity<si::millimeter_t, int> d(a);
        REPL(d);

        constexpr auto e = 3 | si::meter<2> ;
        constexpr auto f = 3 | si::millimeter<2> ;
        REPL(e);
        REPL(f);
        REPL(e + f);

        auto v = (1|si::meters) * (1|si::millimeters);
        auto u = (1|si::centimeters);
        REPL(v);
        REPL(u);
        REPL(v/u);
        quantity<si::millimeter_t, int> milli = u;
        REPL(milli);
        std::cout << "------------------------\n";
    }

    { // Heterogeneous dimesnsion examples
        std::cout << "--[Heterogeneous dimension examples]--\n";
        // speed := km/h
        using speed_t = decltype(si::kilometers/nonsi::hour_t{});

        constexpr quantity<si::meter_t> L(1.2);
        constexpr quantity<si::second_t> T(0.3);
        // unit is automatically convert from m/s to km/h
        quantity<speed_t> V = L/T;
        std::cout << boost::typeindex::type_id<decltype(L*T)>().pretty_name() << std::endl;

        std::cout << V.get() << "[ km/h ]" << std::endl;
        {
            auto w = 36 | si::kilogram<> * si::meter<2> * si::second<-2> * si::ampere<-1>;
            std::cout << boost::typeindex::type_id<decltype(w)>().pretty_name() << std::endl;
        }
        using newton_t = decltype(si::kilogram<> * si::meter<> * si::second<-2>);
        quantity<newton_t> N = (1.0|si::kilograms) * V / (2|si::seconds);
        REPL(N);
        std::cout << "------------------------\n";
    }

    { // compare examples
        std::cout << "--[dimension type comparisons examples]--\n";
        std::cout << std::boolalpha;
        REPL((1|si::meters) == (1|si::millimeters));
        REPL((1|si::meters) == (1000|si::millimeters));
        REPL((1|si::meters) != (1|si::millimeters));
        REPL((1|si::meters) != (1000|si::millimeters));
        REPL((1|si::meters) < (1|si::millimeters));
        REPL((1|si::meters) > (1|si::millimeters));
        REPL((1|si::meters) < (1000|si::millimeters));
        REPL((1|si::meters) > (1000|si::millimeters));
        REPL((1|si::meters) <= (1000|si::millimeters));
        REPL((1|si::meters) >= (1000|si::millimeters));
        std::cout << "------------------------\n";
    }

    { // math function examples
        std::cout << "--[dimension type math functions examples]--\n";
        quantity_t<std::decay_t<decltype(si::millimeter<2>)>, double> v = (1|si::meters) * (1|si::millimeters);
        REPL(sqrt(v));
        REPL(cbrt(v));

        REPL(min((1|si::meters),(1|si::millimeters),(1|si::centimeters)));
        REPL(max((1|si::meters),(1|si::millimeters),(1|si::centimeters)));
        std::cout << "------------------------\n";

        REPL(pow<5>(2|si::meters));
        REPL(square(2|si::meters));
        REPL(cubic(2|si::meters));

        REPL(hypot(2.|si::meters, 2.|si::meters));

        REPL(ceil(2.2|si::meters));
        REPL(floor(2.2|si::meters));
        REPL(trunc(2.2|si::meters));
        REPL(round(2.2|si::meters));
        REPL(lround(2.2|si::meters));
        REPL(llround(2.2|si::meters));
        REPL(nearbyint(2.2|si::meters));
        REPL(rint(2.2|si::meters));
        REPL(lrint(2.2|si::meters));
        REPL(llrint(2.2|mitama::milli*si::meters));
    }

    { // User defined dimension examples
        // currency units
        REPL(100|yen);
    }

    { // User defined dimension examples
        // currency units
        REPL(100|dgree_celsius);
        quantity<si::kelvin_t> s( 100.|nonsi::dgree_celsius );
        REPL(s);
    }

    {
        quantity<kelvin_t> hoge = as_expr(1|kelvins) + (2|dgree_celsius);
        REPL(hoge);
    }

    {
        quantity_t a1 = refined<area_r> |= (2|si::meters) * (7|si::meters);
        REPL(a1);

        quantity_t a2 = refined<area_r> |= (2|si::millimeters) * (7|si::millimeters);
        REPL(a2);

        // error!
        // quantity_t a3 = refined<area_r> |= (2|si::millimeters);

        quantity_t a3 = partial_refined<sym::M<>> |= (2|si::meters) * (2|si::meters) * (2|kilograms) / (2|second<2>);
        REPL(a3);
    }

    {
        delta d = (2|si::meters) - (1|si::meters);
        REPL(d + (1|si::meters));
    }
}