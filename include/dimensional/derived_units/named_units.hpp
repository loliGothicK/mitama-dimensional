#pragma once
#include "../si/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
// dimensionless
namespace mitama {
struct angle { using is_base_dimension = void; };
using radian_t = make_unit_t<angle>;
inline constexpr radian_t radian{};
template <> struct symbol_<angle> { static constexpr char str[] = "rad"; };

struct solid_angle { using is_base_dimension = void; };
using steradian_t = make_unit_t<solid_angle>;
inline constexpr steradian_t steradian{};
template <> struct symbol_<solid_angle> { static constexpr char str[] = "sr"; };
}

namespace mitama {
using hertz_t = powered_t<second_t, -1>;
using newton_t = decltype(kilogram<> * meter<> * second<-2>);
using pascal_t = decltype(kilogram<> * meter<-1> * second<-2>);
using joule_t = decltype(kilogram<> * meter<2> * second<-2>);
using watt_t = decltype(kilogram<> * meter<2> * second<-3>);
using coulomb_t = decltype(second<> * ampere<>);
using volt_t = decltype(kilogram<> * meter<2> * second<-3> * ampere<-1>);
using farad_t = decltype(kilogram<-1> * meter<-2> * second<4> * ampere<2>);
using ohm_t = decltype(kilogram<> * meter<2> * second<-3> * ampere<-2>);
using siemens_t = decltype(kilogram<-1> * meter<-2> * second<3> * ampere<2>);
using weber_t = decltype(kilogram<> * meter<2> * second<-2> * ampere<-1>);
using tesla_t = decltype(kilogram<> * second<-2> * ampere<-1>);
using henry_t = decltype(kilogram<> * meter<2> * second<-2> * ampere<-2>);
using lumen_t = decltype(candela<> * steradian);
using lux_t = decltype(meter<-2> * candela<>);
using becquerel_t = powered_t<second_t, -1>;
using gray_t = decltype(meter<2> * second<-2>);
using sievert_t = decltype(meter<2> * second<-2>);
using katal_t = decltype(second<-1> * mol<>);

template <> struct abbreviation<hertz_t> { static constexpr char str[] = "Hz"; };
template <> struct abbreviation<newton_t> { static constexpr char str[] = "N"; };
template <> struct abbreviation<pascal_t> { static constexpr char str[] = "Pa"; };
template <> struct abbreviation<joule_t> { static constexpr char str[] = "J"; };
template <> struct abbreviation<watt_t> { static constexpr char str[] = "W"; };
template <> struct abbreviation<coulomb_t> { static constexpr char str[] = "C"; };
template <> struct abbreviation<volt_t> { static constexpr char str[] = "V"; };
template <> struct abbreviation<farad_t> { static constexpr char str[] = "F"; };
template <> struct abbreviation<siemens_t> { static constexpr char str[] = "S"; };
template <> struct abbreviation<weber_t> { static constexpr char str[] = "Wb"; };
template <> struct abbreviation<tesla_t> { static constexpr char str[] = "T"; };
template <> struct abbreviation<henry_t> { static constexpr char str[] = "H"; };
template <> struct abbreviation<lumen_t> { static constexpr char str[] = "lm"; };
template <> struct abbreviation<lux_t> { static constexpr char str[] = "lx"; };
template <> struct abbreviation<gray_t> { static constexpr char str[] = "Gy"; };
// template <> struct abbreviation<sievert_t> { static constexpr char str[] = "Sv"; };
template <> struct abbreviation<katal_t> { static constexpr char str[] = "kat"; };
}
