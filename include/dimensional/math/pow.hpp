#ifndef MITAMA_DIMENSIONAL_MATH_POW_HPP
#define MITAMA_DIMENSIONAL_MATH_POW_HPP

#include <cmath>
#include "../quantity.hpp"

namespace mitama {

template < class Exp, template <class> class Synonym, class T, class... Units >
auto pow(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    using std::pow;
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, Exp>::type>, T>
        {
            static_cast<T>(pow(quantity.value(), static_cast<long double>(Exp::num) / Exp::den))
        };
}

template < std::intmax_t Exp, template <class> class Synonym, class T, class... Units >
auto pow(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    using std::pow;
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<Exp>>::type>, T>
        {
            static_cast<T>(pow(quantity.value(), static_cast<long double>(Exp)))
        };
}

template < template <class> class Synonym, class T, class... Units >
auto square(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<2>>::type>, T>
        {
            static_cast<T>(quantity.value() * quantity.value())
        };
}

template < template <class> class Synonym, class T, class... Units >
auto cubic(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<3>>::type>, T>
        {
            static_cast<T>(quantity.value() * quantity.value() * quantity.value())
        };
}
}

#endif