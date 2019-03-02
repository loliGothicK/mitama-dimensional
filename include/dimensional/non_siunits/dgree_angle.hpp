/*
http://d.hatena.ne.jp/osyo-manga/20100811/1281489874

*/
#define _USE_MATH_DEFINES

#pragma once
#include "../units.hpp"
#include "../quotient.hpp"

#include <cmath>


namespace mitama {
// base dimension
struct dgree_angle {
    using is_base_dimension = void;
};

using radian_t = make_unit_t<dgree_angle>;

using angle_t = scaled_unit_t<radian_t, std::ratio<180*100000000000000,(long long)(M_PI)*100000000000000> >;

inline constexpr radian_t radians;

inline constexpr angle_t angles;

template < std::intmax_t N = 1 > inline constexpr powered_t<radian_t, N> radian{};
template < std::intmax_t N = 1 > inline constexpr powered_t<angle_t, N> angle{};

// base unit


} 
