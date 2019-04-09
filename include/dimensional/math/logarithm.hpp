#ifndef MITAMA_DIMENSIONAL_MATH_LOGATITHM_HPP
#define MITAMA_DIMENSIONAL_MATH_LOGATITHM_HPP
#include <cmath>
#include "../quantity.hpp"
#include "../arithmetic.hpp"

namespace mitama {
template <template <class> class Repr,
          class T, class... Units >
auto log(quantity_t<Repr<dimensional_t<Units...>>, T> const& q)
    -> quantity_t<si_base_units_repr<dimensional_t<>>, T>
{
    return {std::log(q.get())};
}

template <template <class> class Repr,
          class T, class... Units >
auto log2(quantity_t<Repr<dimensional_t<Units...>>, T> const& q)
    -> quantity_t<si_base_units_repr<dimensional_t<>>, T>
{
    return {std::log2(q.get())};
}

template <template <class> class Repr,
          class T, class... Units >
auto log10(quantity_t<Repr<dimensional_t<Units...>>, T> const& q)
    -> quantity_t<si_base_units_repr<dimensional_t<>>, T>
{
    return {std::log10(q.get())};
}

template <template <class> class Repr,
          class T, class... Units >
auto log1p(quantity_t<Repr<dimensional_t<Units...>>, T> const& q)
    -> quantity_t<si_base_units_repr<dimensional_t<>>, T>
{
    return {std::log1p(q.get())};
}

}

#endif
