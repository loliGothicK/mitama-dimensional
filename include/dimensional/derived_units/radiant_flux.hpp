#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANT_FLUX_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANT_FLUX_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using radiant_flux_t = decltype(kilogram<> * meter<2> * second<-3>);

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_HPP
inline constexpr radiant_flux_t watt{};
#endif
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_HPP
namespace mitama {
template <> struct abbreviation<si::radiant_flux_t> { static constexpr char str[] = "W"; };
}
#endif

#endif
