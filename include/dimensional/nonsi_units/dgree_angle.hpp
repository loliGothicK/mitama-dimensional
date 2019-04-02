#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_DGREE_ANGLE_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_DGREE_ANGLE_HPP
#include "../quantity.hpp"
#include "../derived_units/angle.hpp"

namespace mitama {

namespace nonsi {
struct dgree_angle { using is_base_dimension = void;};
}

template <> struct symbol_<::mitama::nonsi::dgree_angle> {
  static constexpr char str[] = "°";
};

using dgree_angle_t = make_unit_t<nonsi::dgree_angle>;

inline constexpr dgree_angle_t angle{};

template <class From, class To>
struct converter<quantity_t<si::radian_t, From>,
                 quantity_t<dgree_angle_t, To>>
{
    static constexpr To convert(quantity_t<si::radian_t, From> const& c)
        { return static_cast<To>(c.get() * 57.2957795130823208767l ); }
};
template <class From, class To>
struct converter<quantity_t<dgree_angle_t, From>,
                 quantity_t<si::radian_t, To>>
{
    static constexpr To convert(quantity_t<dgree_angle_t, From> const& s)
        { return static_cast<To>(s.get() / 57.2957795130823208767l ); }
};


}

#endif
