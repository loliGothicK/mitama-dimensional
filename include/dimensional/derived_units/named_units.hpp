#pragma once
#include "../si/all.hpp"

// dimensionless
namespace mitama {
struct angle { using is_base_dimension = void; };
using radian_t = make_unit_t<angle>;
inline constexpr radian_t radian{};

struct solid_angle { using is_base_dimension = void; };
using steradian_t = make_unit_t<solid_angle>;
inline constexpr steradian_t steradian{};
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
}