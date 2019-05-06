#ifndef MITAMA_DIMENSIONAL_MATH_MODULAR_HPP
#define MITAMA_DIMENSIONAL_MATH_MODULAR_HPP

#include <cmath>
#include "../quantity.hpp"
#include "../arithmetic.hpp"

namespace mitama {

template <template <class> class Synonym1,
          template <class> class Synonym2,
          class T1, class... Units1,
          class T2, class... Units2 >
auto fmod(quantity_t<Synonym1<dimensional_t<Units1...>>, T1> const& q1,
          quantity_t<Synonym2<dimensional_t<Units2...>>, T2> const& q2)
    -> std::enable_if_t<std::is_convertible_v<T1, long double> && std::is_convertible_v<T2, long double>,
            std::decay_t<decltype(q1/q2)>>
{
    return std::decay_t<decltype(q1/q2)>(std::fmod(q1.value(), q2.value()));
}

template < template <class> class Synonym, class T, class... Units >
auto fmod(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity,
          typename quantity_t<Synonym<dimensional_t<Units...>>, T>::value_type value)
{
    return std::decay_t<decltype(quantity)>{ std::fmod(quantity.value(), value) };
}

template <template <class> class Synonym1,
          template <class> class Synonym2,
          class T1, class... Units1,
          class T2, class... Units2 >
auto remainder(quantity_t<Synonym1<dimensional_t<Units1...>>, T1> const& q1,
               quantity_t<Synonym2<dimensional_t<Units2...>>, T2> const& q2)
    -> std::enable_if_t<std::is_convertible_v<T1, long double> && std::is_convertible_v<T2, long double>,
            std::decay_t<decltype(q1/q2)>>
{
    return std::decay_t<decltype(q1/q2)>(std::remainder(q1.value(), q2.value()));
}

template < template <class> class Synonym, class T, class... Units >
auto remainder(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity,
               typename quantity_t<Synonym<dimensional_t<Units...>>, T>::value_type value)
{
    return std::decay_t<decltype(quantity)>{ std::remainder(quantity.value(), value) };
}


}

#endif