#include "../include/quantity.hpp"
#include "../include/arithmetic.hpp"
#include "../include/si/meters.hpp"
#include <boost/type_index.hpp>
#include <iostream>

int main(){
    using namespace mitama;

    quantity<meters, int> a(2);
    quantity<millimeters, int> b(2);
    auto r1 = a + b;
    std::cout << boost::typeindex::type_id<decltype(r1)>().pretty_name() << std::endl;
    std::cout << r1.get() << std::endl;
    auto r2 = a - b;
    std::cout << boost::typeindex::type_id<decltype(r2)>().pretty_name() << std::endl;
    std::cout << r2.get() << std::endl;
    auto r3 = a * b;
    std::cout << boost::typeindex::type_id<decltype(r3)>().pretty_name() << std::endl;
    std::cout << r3.get() << std::endl;
    auto r4 = a / b;
    std::cout << boost::typeindex::type_id<decltype(r4)>().pretty_name() << std::endl;
    std::cout << r4.get() << std::endl;

}