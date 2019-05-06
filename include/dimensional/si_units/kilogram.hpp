#ifndef MITAMA_DIMENSIONAL_SI_UNITS_KILOGRAM_HPP
#define MITAMA_DIMENSIONAL_SI_UNITS_KILOGRAM_HPP
#include "../quantity.hpp"

namespace mitama::si {
// base dimension
struct mass {
    using is_base_dimension = void;
};

// base unit
using kilogram_t = make_unit_t<mass>;
using gram_t = scaled_unit_t<kilogram_t, std::milli>;
using milligram_t = scaled_unit_t<gram_t, std::milli>;
using microgram_t = scaled_unit_t<gram_t, std::micro>;
using nanogram_t = scaled_unit_t<gram_t, std::nano>;

template < std::intmax_t N = 1 >
using kilogram_ = powered_t<kilogram_t, N>;
template < std::intmax_t N = 1 >
using gram_ = powered_t<gram_t, N>;
template < std::intmax_t N = 1 >
using milligram_ = powered_t<milligram_t, N>;
template < std::intmax_t N = 1 >
using microgram_ = powered_t<microgram_t, N>;
template < std::intmax_t N = 1 >
using nanogram_ = powered_t<nanogram_t, N>;

inline constexpr kilogram_t kilograms;
inline constexpr gram_t grams;
inline constexpr milligram_t milligrams;
inline constexpr microgram_t micrograms;
inline constexpr nanogram_t nanograms;

template < std::intmax_t N = 1> inline constexpr powered_t<kilogram_t, N> kilogram{};
template < std::intmax_t N = 1> inline constexpr powered_t<gram_t, N> gram{};
template < std::intmax_t N = 1> inline constexpr powered_t<milligram_t, N> milligram{};
template < std::intmax_t N = 1> inline constexpr powered_t<microgram_t, N> microgram{};
template < std::intmax_t N = 1> inline constexpr powered_t<nanogram_t, N> nanogram{};

}

#endif