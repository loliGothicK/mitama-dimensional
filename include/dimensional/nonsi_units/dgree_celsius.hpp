#ifndef MITAMA_DIMENSIONAL_SI_DERIVED_DGREE_CELSIUS_HPP
#define MITAMA_DIMENSIONAL_SI_DERIVED_DGREE_CELSIUS_HPP

#include "../si_units/kelvin.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::nonsi {
struct celsius_temperature { using is_base_dimension = void; };
}

namespace mitama {
template <> struct symbol_<::mitama::nonsi::celsius_temperature> {
  static constexpr char str[] = "°C";
};
}
namespace mitama::nonsi {

using dgree_celsius_t = make_unit_t<nonsi::celsius_temperature>;

inline constexpr dgree_celsius_t dgree_celsius{};
}

namespace mitama {
template <class From, class To>
struct converter<quantity_t<nonsi::dgree_celsius_t, From>,
                 quantity_t<si::kelvin_t, To>>
{
    static constexpr To convert(quantity_t<nonsi::dgree_celsius_t, From> const& c)
        { return static_cast<To>(c.get() + 273.15); }
};
template <class From, class To>
struct converter<quantity_t<si::kelvin_t, From>,
                 quantity_t<nonsi::dgree_celsius_t, To>>
{
    static constexpr To convert(quantity_t<si::kelvin_t, From> const& s)
        { return static_cast<To>(s.get() - 273.15); }
};

}

#endif