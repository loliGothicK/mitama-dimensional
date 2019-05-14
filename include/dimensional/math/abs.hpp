#ifndef MITAMA_DIMENSIONAL_MATH_ABS_HPP
#define MITAMA_DIMENSIONAL_MATH_ABS_HPP

#include <cmath>
#include <dimensional/quantity.hpp>

namespace mitama {

template < template <class> class Synonym, class T, class... Units >
auto abs(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    using std::abs;
    return std::decay_t<decltype(quantity)>{ abs(quantity.value()) };
}

}

#endif