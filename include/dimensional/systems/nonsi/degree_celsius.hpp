#ifndef MITAMA_DIMENSIONAL_SI_DERIVED_DEGREE_CELSIUS_HPP
#define MITAMA_DIMENSIONAL_SI_DERIVED_DEGREE_CELSIUS_HPP

#include <dimensional/systems/si/kelvin.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

namespace mitama::systems::nonsi {
struct celsius_temperature { using is_base_dimension = void; };
}

namespace mitama {
template <> struct symbol_<::mitama::systems::nonsi::celsius_temperature> {
  static constexpr char str[] = "°C";
};
}
namespace mitama::systems::nonsi {

using degree_celsius_t = make_unit_t<systems::nonsi::celsius_temperature>;

inline constexpr degree_celsius_t degree_celsius{};
}

namespace mitama {
template <class From, class To>
struct converter<quantity_t<systems::nonsi::degree_celsius_t, From>,
                 quantity_t<systems::si::kelvin_t, To>>
{
    static constexpr To convert(quantity_t<systems::nonsi::degree_celsius_t, From> const& c)
        { return static_cast<To>(c.value() + 273.15); }
};
template <class From, class To>
struct converter<quantity_t<systems::si::kelvin_t, From>,
                 quantity_t<systems::nonsi::degree_celsius_t, To>>
{
    static constexpr To convert(quantity_t<systems::si::kelvin_t, From> const& s)
        { return static_cast<To>(s.value() - 273.15); }
};

}

#endif