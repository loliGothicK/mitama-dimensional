#include "../include/quantity.hpp"
#include "../include/arithmetic.hpp"
#include "../include/si/meter.hpp"
#include "../include/si/second.hpp"
#include "../include/io.hpp"
#include <boost/type_index.hpp>
#include <iostream>

int main(){
    using namespace mitama;
    { // Homogeneous dimension examples
        constexpr quantity<meter_t, int> a(2);
        constexpr quantity<millimeter_t, int> b(2);
        constexpr auto r1 = a + b;
        std::cout << r1 << std::endl;
        constexpr auto r2 = a - b;
        std::cout << r2 << std::endl;
        constexpr auto r3 = a * b;
        std::cout << r3 << std::endl;
        constexpr auto r4 = a / b;
        std::cout << r4 << std::endl;

        constexpr quantity<millimeter_t, int> d(a);
        std::cout << d << std::endl;

        constexpr auto e = 3 | meter<2> ;
        constexpr auto f = 3 | millimeter<2> ;
        std::cout << e << std::endl;
        std::cout << f << std::endl;
        std::cout << e + f << std::endl;
    }

    { // Heterogeneous dimesnsion examples
        using hours = scaled_unit_t<second_t, std::ratio<3600>>;
        using velocity = decltype(kilometers/hours{});
        constexpr quantity<meter_t> L(1.2);
        constexpr quantity<second_t> T(0.3);

        constexpr quantity<velocity> V = L/T;

        std::cout << V.get() << "[ km/h ]" << std::endl;
    }
}