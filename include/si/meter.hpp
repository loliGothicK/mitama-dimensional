#pragma once
#include "../units.hpp"

namespace mitama {
// base dimension
struct length {};

// base unit
using meter_t = make_unit_t<length>;

using picometer_t = scaled_unit_t<meter_t, std::pico>;
using nanometer_t = scaled_unit_t<meter_t, std::nano>;
using micrometer_t = scaled_unit_t<meter_t, std::micro>;
using millimeter_t = scaled_unit_t<meter_t, std::milli>;
using centimeter_t = scaled_unit_t<meter_t, std::centi>;
using decimeter_t = scaled_unit_t<meter_t, std::deci>;

using decameter_t = scaled_unit_t<meter_t, std::deca>;
using hectometer_t = scaled_unit_t<meter_t, std::hecto>;
using kilometer_t = scaled_unit_t<meter_t, std::kilo>;
using megameter_t = scaled_unit_t<meter_t, std::mega>;
using gigameter_t = scaled_unit_t<meter_t, std::giga>;
using terameter_t = scaled_unit_t<meter_t, std::tera>;

inline constexpr meter_t meters;

inline constexpr picometer_t picometers;
inline constexpr nanometer_t nanometers;
inline constexpr micrometer_t micrometers;
inline constexpr millimeter_t millimeters;
inline constexpr centimeter_t centimeters;
inline constexpr decimeter_t decimeters;

inline constexpr kilometer_t kilometers;
inline constexpr megameter_t megameters;
inline constexpr gigameter_t gigameters;
inline constexpr terameter_t terameters;

template < std::intmax_t N = 1 > inline constexpr powered_t<meter_t, N> meter{};

template < std::intmax_t N = 1 > inline constexpr powered_t<picometer_t, N> picometer{};
template < std::intmax_t N = 1 > inline constexpr powered_t<nanometer_t, N> nanometer{};
template < std::intmax_t N = 1 > inline constexpr powered_t<micrometer_t, N> micrometer{};
template < std::intmax_t N = 1 > inline constexpr powered_t<millimeter_t, N> millimeter{};
template < std::intmax_t N = 1 > inline constexpr powered_t<centimeter_t, N> centimeter{};

template < std::intmax_t N = 1 > inline constexpr powered_t<kilometer_t, N> kilometer{};
template < std::intmax_t N = 1 > inline constexpr powered_t<megameter_t, N> megameter{};
template < std::intmax_t N = 1 > inline constexpr powered_t<gigameter_t, N> gigameter{};
template < std::intmax_t N = 1 > inline constexpr powered_t<terameter_t, N> terameter{};


}