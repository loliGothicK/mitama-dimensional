#ifndef MITAMA_DIMENSIONAL_MATH_POW_HPP
#define MITAMA_DIMENSIONAL_MATH_POW_HPP

#include <cmath>
#include "../quantity.hpp"

namespace mitama {

template < class Exp, template <class> class Repr, class T, class... Units >
auto pow(quantity_t<Repr<dimensional_t<Units...>>, T> const& quantity) {
    return quantity_t<Repr<typename mitamagic::powered_dimensional<dimensional_t<Units...>, Exp>::type>, T>
        {
            static_cast<T>(std::pow(quantity.get(), static_cast<long double>(Exp::num) / Exp::den))
        };
}

template < std::intmax_t Exp, template <class> class Repr, class T, class... Units >
auto pow(quantity_t<Repr<dimensional_t<Units...>>, T> const& quantity) {
    return quantity_t<Repr<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<Exp>>::type>, T>
        {
            static_cast<T>(std::pow(quantity.get(), static_cast<long double>(Exp)))
        };
}

template < template <class> class Repr, class T, class... Units >
auto square(quantity_t<Repr<dimensional_t<Units...>>, T> const& quantity) {
    return quantity_t<Repr<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<2>>::type>, T>
        {
            static_cast<T>(quantity.get() * quantity.get())
        };
}

template < template <class> class Repr, class T, class... Units >
auto cubic(quantity_t<Repr<dimensional_t<Units...>>, T> const& quantity) {
    return quantity_t<Repr<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<3>>::type>, T>
        {
            static_cast<T>(quantity.get() * quantity.get() * quantity.get())
        };
}
}

#endif