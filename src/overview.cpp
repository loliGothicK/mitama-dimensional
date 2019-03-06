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
        constexpr quantity<meter_t, int> a = 2;
        constexpr quantity<millimeter_t, int> b = 2;
        
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

        quantity<millimeter_t, int> d(a);
        REPL(d);

        constexpr auto e = 3 | meter<2> ;
        constexpr auto f = 3 | millimeter<2> ;
        REPL(e);
        REPL(f);
        REPL(e + f);

        auto v = (1|meters) * (1|millimeters);
        auto u = (1|centimeters);
        REPL(v);
        REPL(u);
        REPL(v/u);
        quantity<millimeter_t, int> milli = u;
        REPL(milli);
        std::cout << "------------------------\n";
    }

    { // Heterogeneous dimesnsion examples
        std::cout << "--[Heterogeneous dimension examples]--\n";
        // 1 hour := 3600 s
        using hour_t = scaled_unit_t<second_t, std::ratio<3600>>;
        // speed := km/h
        using speed_t = decltype(kilometers/hour_t{});

        constexpr quantity<meter_t> L(1.2);
        constexpr quantity<second_t> T(0.3);
        // unit is automatically convert from m/s to km/h
        quantity<speed_t> V = L/T;
        std::cout << boost::typeindex::type_id<decltype(L*T)>().pretty_name() << std::endl;

        std::cout << V.get() << "[ km/h ]" << std::endl;
        {
            auto w = 36 | kilogram<> * meter<2> * second<-2> * ampere<-1>;
            std::cout << boost::typeindex::type_id<decltype(w)>().pretty_name() << std::endl;
            // auto refined_ = refined<sym::L<>,sym::T<-1>>(w).get();
            // std::cout << refined_ << std::endl;
        }
        using newton_t = decltype(kilogram<> * meter<> * second<-2>);
        quantity<newton_t> N = (1.0|kilograms) * V / (2|seconds);
        REPL(N);
        std::cout << "------------------------\n";
    }

    { // compare examples
        std::cout << "--[dimension type comparisons examples]--\n";
        std::cout << std::boolalpha;
        REPL((1|meters) == (1|millimeters));
        REPL((1|meters) == (1000|millimeters));
        REPL((1|meters) != (1|millimeters));
        REPL((1|meters) != (1000|millimeters));
        REPL((1|meters) < (1|millimeters));
        REPL((1|meters) > (1|millimeters));
        REPL((1|meters) < (1000|millimeters));
        REPL((1|meters) > (1000|millimeters));
        REPL((1|meters) <= (1000|millimeters));
        REPL((1|meters) >= (1000|millimeters));
        std::cout << "------------------------\n";
    }

    { // math function examples
        std::cout << "--[dimension type math functions examples]--\n";
        quantity_t<std::decay_t<decltype(millimeter<2>)>, double> v = (1|meters) * (1|millimeters);
        REPL(sqrt(v));
        REPL(cbrt(v));

        REPL(min((1|meters),(1|millimeters),(1|centimeters)));
        REPL(max((1|meters),(1|millimeters),(1|centimeters)));
        std::cout << "------------------------\n";

        REPL(pow<5>(2|meters));
        REPL(square(2|meters));
        REPL(cubic(2|meters));

        REPL(hypot(2.|meters, 2.|meters));

        REPL(ceil(2.2|meters));
        REPL(floor(2.2|meters));
        REPL(trunc(2.2|meters));
        REPL(round(2.2|meters));
        REPL(lround(2.2|meters));
        REPL(llround(2.2|meters));
        REPL(nearbyint(2.2|meters));
        REPL(rint(2.2|meters));
        REPL(lrint(2.2|meters));
        REPL(llrint(2.2|mitama::milli*meters));
    }

    { // User defined dimension examples
        // currency units
        REPL(100|yen);
    }

    { // User defined dimension examples
        // currency units
        REPL(100|dgree_celsius);
        quantity<kelvin_t> s( 100.|dgree_celsius );
        REPL(s);
    }

    {
        quantity<kelvin_t> hoge = as_expr(1|kelvins) + (2|dgree_celsius);
        REPL(hoge);
    }

}