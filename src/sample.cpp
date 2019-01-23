#include "../include/quantity.hpp"
#include "../include/arithmetic.hpp"
#include "../include/si/meter.hpp"
#include "../include/si/second.hpp"
#include "../include/io.hpp"
#include "../include/math/all.hpp"
#include <boost/type_index.hpp>
#include <iostream>

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
        std::cout << r1 << std::endl;
        
        // `a - b` is valid operation if and only if `a` and `b` has same base dimensions.
        auto r2 = a - b;
        std::cout << r2 << std::endl;
        
        // `a * b` is always valid and:
        // - Result quantity has heterogeneous dimension inducted from `a` and `b`, and
        // - If both a and b values are of the same dimension, these values are automatically scaled to high precision units.
        auto r3 = a * b;
        std::cout << r3 << std::endl;

        // a / b := a * b^{-1}
        auto r4 = a / b;
        std::cout << r4 << std::endl;

        quantity<millimeter_t, int> d(a);
        std::cout << d << std::endl;

        constexpr auto e = 3 | meter<2> ;
        constexpr auto f = 3 | millimeter<2> ;
        std::cout << e << std::endl;
        std::cout << f << std::endl;
        std::cout << e + f << std::endl;

        auto v = (1|meters) * (1|millimeters);
        auto u = (1|centimeters);
        std::cout << v << std::endl;
        std::cout << u << std::endl;
        std::cout << v/u << std::endl;
        quantity<millimeter_t, int> milli = u;
        std::cout << milli << std::endl;
        std::cout << "------------------------\n";
    }

    { // Heterogeneous dimesnsion examples
        std::cout << "--[Heterogeneous dimension examples]--\n";
        // 1 hour := 3600 s
        using hour_t = scaled_unit_t<second_t, std::ratio<3600>>;
        // velocity := km/h
        using velocity_t = decltype(kilometers/hour_t{});

        constexpr quantity<meter_t> L(1.2);
        constexpr quantity<second_t> T(0.3);
        // unit is automatically convert from m/s to km/h
        quantity<velocity_t> V = L/T;

        std::cout << V.get() << "[ km/h ]" << std::endl;
        std::cout << "------------------------\n";
    }

    { // compare examples
        std::cout << "--[dimension type comparisons examples]--\n";
#define TEST(OP) [](auto a, auto b){ std::cout << a << " " << #OP << " " << b << "\n  => " << (a OP b) << std::endl; }
        std::cout << std::boolalpha;
        TEST(==)(1|meters, 1|millimeters);
        TEST(==)(1|meters, 1000|millimeters);
#undef TEST
        std::cout << "------------------------\n";
    }

    { // math function examples
        std::cout << "--[dimension type math functions examples]--\n";
        quantity_t<std::decay_t<decltype(millimeter<2>)>, double> v = (1|meters) * (1|millimeters);
        std::cout << sqrt(v) << std::endl;
        std::cout << cbrt(v) << std::endl;

        std::cout << min((1|meters),(1|millimeters),(1|centimeters)) << std::endl;
        std::cout << max((1|meters),(1|millimeters),(1|centimeters)) << std::endl;
        std::cout << "------------------------\n";

        std::cout << pow<5>(2|meters) << std::endl;
        std::cout << square(2|meters) << std::endl;
        std::cout << cubic(2|meters) << std::endl;

        std::cout << hypot(2.|meters, 2.|meters) << std::endl;
    }
}