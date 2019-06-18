#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_DEGREE_ANGLE_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_DEGREE_ANGLE_HPP
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/derived_units/angle.hpp>

namespace mitama::systems::nonsi {
  using degree_angle_base_unit = base_units<si::angle, 1>;
  using degree_angle_t = typename degree_angle_base_unit::unit_type;
  inline constexpr degree_angle_t angle{};
}

namespace mitama {
template <> struct symbol_<::mitama::systems::si::angle, 1> {
  static constexpr char str[] = "°";
};

template <class From, class To>
struct converter<quantity_t<systems::si::radian_t, From>,
                 quantity_t<systems::nonsi::degree_angle_t, To>>
{
    static constexpr To convert(quantity_t<systems::si::radian_t, From> const& c)
        { return static_cast<To>(c.value() * 57.2957795130823208767l ); }
};
template <class From, class To>
struct converter<quantity_t<systems::nonsi::degree_angle_t, From>,
                 quantity_t<systems::si::radian_t, To>>
{
    static constexpr To convert(quantity_t<systems::nonsi::degree_angle_t, From> const& s)
        { return static_cast<To>(s.value() / 57.2957795130823208767l ); }
};
}

#endif
