#ifndef MITAMA_DIMENSIONAL_MATH_LOGATITHM_HPP
#define MITAMA_DIMENSIONAL_MATH_LOGATITHM_HPP
#include <cmath>
#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>

namespace mitama {
template <template <class> class Synonym,
          class T, class... Units >
auto log(quantity_t<Synonym<dimensional_t<Units...>>, T> const& q)
    -> quantity_t<si_base_units<dimensional_t<>>, T>
{
    using std::log;
    return {log(q.value())};
}

template <template <class> class Synonym,
          class T, class... Units >
auto log2(quantity_t<Synonym<dimensional_t<Units...>>, T> const& q)
    -> quantity_t<si_base_units<dimensional_t<>>, T>
{
    using std::log2;
    return {log2(q.value())};
}

template <template <class> class Synonym,
          class T, class... Units >
auto log10(quantity_t<Synonym<dimensional_t<Units...>>, T> const& q)
    -> quantity_t<si_base_units<dimensional_t<>>, T>
{
    using std::log10;
    return {log10(q.value())};
}

template <template <class> class Synonym,
          class T, class... Units >
auto log1p(quantity_t<Synonym<dimensional_t<Units...>>, T> const& q)
    -> quantity_t<si_base_units<dimensional_t<>>, T>
{
    using std::log1p;
    return {log1p(q.value())};
}

}

#endif
