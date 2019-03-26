#ifndef MITAMA_DIMENSIONAL_MATH_POW_HPP
#define MITAMA_DIMENSIONAL_MATH_POW_HPP

#include <cmath>
#include "../quantity.hpp"

namespace mitama {

template < class Exp, class T, class... Units >
auto pow(quantity_t<dimensional_t<Units...>, T> const& quantity) {
    return quantity_t<typename mitamagic::powered_dimensional<dimensional_t<Units...>, Exp>::type, T>
        {
            static_cast<T>(std::pow(quantity.get(), static_cast<long double>(Exp::num) / Exp::den))
        };
}

template < std::intmax_t Exp, class T, class... Units >
auto pow(quantity_t<dimensional_t<Units...>, T> const& quantity) {
    return quantity_t<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<Exp>>::type, T>
        {
            static_cast<T>(std::pow(quantity.get(), static_cast<long double>(Exp)))
        };
}

template < class T, class... Units >
auto square(quantity_t<dimensional_t<Units...>, T> const& quantity) {
    return quantity_t<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<2>>::type, T>
        {
            static_cast<T>(quantity.get() * quantity.get())
        };
}

template < class T, class... Units >
auto cubic(quantity_t<dimensional_t<Units...>, T> const& quantity) {
    return quantity_t<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<3>>::type, T>
        {
            static_cast<T>(quantity.get() * quantity.get() * quantity.get())
        };
}
}

#endif