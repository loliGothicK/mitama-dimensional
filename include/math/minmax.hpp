#ifndef MITAMA_DIMENSIONAL_MATH_MINMAX_HPP
#define MITAMA_DIMENSIONAL_MATH_MINMAX_HPP

#include <cmath>
#include "../quantity.hpp"
#include "../comparison.hpp"

namespace mitama {

template < class... Quantities >
auto min(Quantities... quantities) {
    return std::min({
        static_cast<::mitama::common_type_t<std::decay_t<Quantities>...>>(quantities)...
    });
}

template < class... Quantities >
auto max(Quantities... quantities) {
    return std::max({
        static_cast<::mitama::common_type_t<std::decay_t<Quantities>...>>(quantities)...
    });
}


}

#endif