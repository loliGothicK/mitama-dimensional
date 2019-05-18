#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_DEGREE_ANGLE_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_DEGREE_ANGLE_HPP
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/derived_units/angle.hpp>

namespace mitama::systems::nonsi {
struct degree_angle {
  using is_base_dimension = void;
  using is_dimensionless = void;
};
}

namespace mitama {
template <> struct symbol_<::mitama::systems::nonsi::degree_angle> {
  static constexpr char str[] = "°";
};

using degree_angle_t = make_unit_t<systems::nonsi::degree_angle>;

inline constexpr degree_angle_t angle{};

template <class From, class To>
struct converter<quantity_t<systems::si::radian_t, From>,
                 quantity_t<degree_angle_t, To>>
{
    static constexpr To convert(quantity_t<systems::si::radian_t, From> const& c)
        { return static_cast<To>(c.value() * 57.2957795130823208767l ); }
};
template <class From, class To>
struct converter<quantity_t<degree_angle_t, From>,
                 quantity_t<systems::si::radian_t, To>>
{
    static constexpr To convert(quantity_t<degree_angle_t, From> const& s)
        { return static_cast<To>(s.value() / 57.2957795130823208767l ); }
};
}

#endif
