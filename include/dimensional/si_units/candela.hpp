#ifndef MITAMA_DIMENSIONAL_SI_UNITS_CANDELA_HPP
#define MITAMA_DIMENSIONAL_SI_UNITS_CANDELA_HPP
#include "../quantity.hpp"

namespace mitama::si {
struct luminous_intensity {
    using is_base_dimension = void;
};

using candela_t = make_unit_t<luminous_intensity>;

template < std::intmax_t N = 1 >
using candela_ = powered_t<candela_t, N>;

inline constexpr candela_t candelas{};

template < std::intmax_t N = 1 > inline constexpr powered_t<candela_t, N> candela{};

}

#endif