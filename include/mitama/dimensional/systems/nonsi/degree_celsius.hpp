#ifndef MITAMA_DIMENSIONAL_NONSI_DEGREE_CELSIUS_HPP
#define MITAMA_DIMENSIONAL_NONSI_DEGREE_CELSIUS_HPP

#include <mitama/dimensional/systems/si/base_units/kelvin.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

namespace mitama::systems::nonsi {
  using degree_celsius_base_unit = base_units<si::thermodynamic_temperature, 1>;
  using degree_celsius_t = typename degree_celsius_base_unit::unit_type;
  inline constexpr degree_celsius_t degree_celsius{};
}

namespace mitama {

template <> struct symbol_<::mitama::systems::si::thermodynamic_temperature, 1> {
  static constexpr char str[] = "°C";
};

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
