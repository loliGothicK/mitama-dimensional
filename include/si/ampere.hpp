#pragma once
#include "../units.hpp"

namespace mitama {
struct electric_current {};

using ampere_t = make_unit_t<electric_current>;

using milliampere_t = scaled_unit_t<ampere_t, std::milli>;
using microampere_t = scaled_unit_t<ampere_t, std::micro>;
using nanoampere_t = scaled_unit_t<ampere_t, std::nano>;

using kiloampere_t = scaled_unit_t<ampere_t, std::kilo>;
using megaampere_t = scaled_unit_t<ampere_t, std::mega>;

inline constexpr ampere_t amperes{};

inline constexpr milliampere_t milliamperes{};
inline constexpr microampere_t microamperes{};
inline constexpr nanoampere_t nanoamperes{};

inline constexpr kiloampere_t kiloamperes{};
inline constexpr megaampere_t megaamperes{};


template < std::intmax_t N = 1 > inline constexpr powered_t<ampere_t, N> ampere{};

template < std::intmax_t N = 1 > inline constexpr powered_t<milliampere_t, N> milliampere{};
template < std::intmax_t N = 1 > inline constexpr powered_t<microampere_t, N> microampere{};
template < std::intmax_t N = 1 > inline constexpr powered_t<nanoampere_t, N> nanoampere{};

template < std::intmax_t N = 1 > inline constexpr powered_t<kiloampere_t, N> kiloampere{};
template < std::intmax_t N = 1 > inline constexpr powered_t<megaampere_t, N> megaampere{};

}