#pragma once
#include "../units.hpp"
#include "../quotient.hpp"

namespace mitama {
// base dimension
struct length {
    using is_base_dimension = void;
};

// base unit
using meter_t = make_unit_t<length>;
using metre_t = make_unit_t<length>;

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

using picometre_t = scaled_unit_t<metre_t, std::pico>;
using nanometre_t = scaled_unit_t<metre_t, std::nano>;
using micrometre_t = scaled_unit_t<metre_t, std::micro>;
using millimetre_t = scaled_unit_t<metre_t, std::milli>;
using centimetre_t = scaled_unit_t<metre_t, std::centi>;
using decimetre_t = scaled_unit_t<metre_t, std::deci>;

using decametre_t = scaled_unit_t<metre_t, std::deca>;
using hectometre_t = scaled_unit_t<metre_t, std::hecto>;
using kilometre_t = scaled_unit_t<metre_t, std::kilo>;
using megametre_t = scaled_unit_t<metre_t, std::mega>;
using gigametre_t = scaled_unit_t<metre_t, std::giga>;
using terametre_t = scaled_unit_t<metre_t, std::tera>;

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

inline constexpr picometre_t picometres;
inline constexpr nanometre_t nanometres;
inline constexpr micrometre_t micrometres;
inline constexpr millimetre_t millimetres;
inline constexpr centimetre_t centimetres;
inline constexpr decimetre_t decimetres;

inline constexpr kilometre_t kilometres;
inline constexpr megametre_t megametres;
inline constexpr gigametre_t gigametres;
inline constexpr terametre_t terametres;


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

template < std::intmax_t N = 1 > inline constexpr powered_t<metre_t, N> metre{};

template < std::intmax_t N = 1 > inline constexpr powered_t<picometre_t, N> picometre{};
template < std::intmax_t N = 1 > inline constexpr powered_t<nanometre_t, N> nanometre{};
template < std::intmax_t N = 1 > inline constexpr powered_t<micrometre_t, N> micrometre{};
template < std::intmax_t N = 1 > inline constexpr powered_t<millimetre_t, N> millimetre{};
template < std::intmax_t N = 1 > inline constexpr powered_t<centimetre_t, N> centimetre{};

template < std::intmax_t N = 1 > inline constexpr powered_t<kilometre_t, N> kilometre{};
template < std::intmax_t N = 1 > inline constexpr powered_t<megametre_t, N> megametre{};
template < std::intmax_t N = 1 > inline constexpr powered_t<gigametre_t, N> gigametre{};
template < std::intmax_t N = 1 > inline constexpr powered_t<terametre_t, N> terametre{};


}