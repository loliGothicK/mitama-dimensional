#ifndef MITAMA_DIMENSIONAL_MATH_POW_HPP
#define MITAMA_DIMENSIONAL_MATH_POW_HPP

#include <cmath>
#include "../quantity.hpp"

namespace mitama {

template < class Exp, class T, class _, class... Units >
auto pow(quantity_t<dimensional_t<_, Units...>, T> const& quantity) {
    return quantity_t<typename mitamagic::powered_dimensional<dimensional_t<_, Units...>, Exp>::type, T>
        {
            static_cast<T>(std::pow(quantity.get(), static_cast<long double>(Exp::num) / Exp::den))
        };
}

template < std::intmax_t Exp, class T, class _, class... Units >
auto pow(quantity_t<dimensional_t<_, Units...>, T> const& quantity) {
    return quantity_t<typename mitamagic::powered_dimensional<dimensional_t<_, Units...>, std::ratio<Exp>>::type, T>
        {
            static_cast<T>(std::pow(quantity.get(), static_cast<long double>(Exp)))
        };
}

template < class T, class _, class... Units >
auto square(quantity_t<dimensional_t<_, Units...>, T> const& quantity) {
    return quantity_t<typename mitamagic::powered_dimensional<dimensional_t<_, Units...>, std::ratio<2>>::type, T>
        {
            static_cast<T>(std::pow(quantity.get(), 2.0l))
        };
}

template < class T, class _, class... Units >
auto cubic(quantity_t<dimensional_t<_, Units...>, T> const& quantity) {
    return quantity_t<typename mitamagic::powered_dimensional<dimensional_t<_, Units...>, std::ratio<3>>::type, T>
        {
            static_cast<T>(std::pow(quantity.get(), 3.0l))
        };
}
}

#endif