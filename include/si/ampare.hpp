#pragma once
#include "../units.hpp"

namespace mitama {
struct electric_current {};

using ampare_t = make_unit_t<electric_current>;

using milliampare_t = scaled_unit_t<ampare_t, std::milli>;
using microampare_t = scaled_unit_t<ampare_t, std::micro>;
using nanoampare_t = scaled_unit_t<ampare_t, std::nano>;

using kiloampare_t = scaled_unit_t<ampare_t, std::kilo>;
using megaampare_t = scaled_unit_t<ampare_t, std::mega>;

inline constexpr ampare_t ampares{};

inline constexpr milliampare_t milliampares{};
inline constexpr microampare_t microampares{};
inline constexpr nanoampare_t nanoampares{};

inline constexpr kiloampare_t kiloampares{};
inline constexpr megaampare_t megaampares{};


template < std::intmax_t N > inline constexpr powered_t<ampare_t, N> ampare{};

template < std::intmax_t N > inline constexpr powered_t<milliampare_t, N> milliampare{};
template < std::intmax_t N > inline constexpr powered_t<microampare_t, N> microampare{};
template < std::intmax_t N > inline constexpr powered_t<nanoampare_t, N> nanoampare{};

template < std::intmax_t N > inline constexpr powered_t<kiloampare_t, N> kiloampare{};
template < std::intmax_t N > inline constexpr powered_t<megaampare_t, N> megaampare{};

}