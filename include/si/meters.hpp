#pragma once
#include "../units.hpp"

namespace mitama {

using meters_t = make_unit_t<Length>;

using attometers_t = scaled_unit_t<meters_t, std::atto>;
using femtometers_t = scaled_unit_t<meters_t, std::femto>;
using picometers_t = scaled_unit_t<meters_t, std::pico>;
using nanometers_t = scaled_unit_t<meters_t, std::nano>;
using micrometers_t = scaled_unit_t<meters_t, std::micro>;
using millimeters_t = scaled_unit_t<meters_t, std::milli>;
using centimeters_t = scaled_unit_t<meters_t, std::centi>;
using decimeters_t = scaled_unit_t<meters_t, std::deci>;

using decameters_t = scaled_unit_t<meters_t, std::deca>;
using hectometers_t = scaled_unit_t<meters_t, std::hecto>;
using kilometers_t = scaled_unit_t<meters_t, std::kilo>;
using megameters_t = scaled_unit_t<meters_t, std::mega>;
using gigameters_t = scaled_unit_t<meters_t, std::giga>;
using terameters_t = scaled_unit_t<meters_t, std::tera>;
using petameters_t = scaled_unit_t<meters_t, std::peta>;
using exameters_t = scaled_unit_t<meters_t, std::exa>;

inline constexpr meters_t meters;

inline constexpr attometers_t attometers;
inline constexpr femtometers_t femtometers;
inline constexpr picometers_t picometers;
inline constexpr nanometers_t nanometers;
inline constexpr micrometers_t micrometers;
inline constexpr millimeters_t millimeters;
inline constexpr centimeters_t centimeters;
inline constexpr decimeters_t decimeters;

inline constexpr decameters_t decameters;
inline constexpr hectometers_t hectometers;
inline constexpr kilometers_t kilometers;
inline constexpr megameters_t megameters;
inline constexpr gigameters_t gigameters;
inline constexpr terameters_t terameters;
inline constexpr petameters_t petameters;
inline constexpr exameters_t exameters;


}