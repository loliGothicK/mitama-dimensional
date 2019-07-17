#ifndef MITAMA_DIMENSIONAL_MATH_ABS_HPP
#define MITAMA_DIMENSIONAL_MATH_ABS_HPP

#include <cmath>
#include <mitama/dimensional/quantity.hpp>

namespace mitama {

template < template <class> class Synonym, class T, class... Units, class S >
auto abs(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const& quantity) {
    using std::abs;
    return std::decay_t<decltype(quantity)>{ abs(quantity.value()) };
}

}

#endif