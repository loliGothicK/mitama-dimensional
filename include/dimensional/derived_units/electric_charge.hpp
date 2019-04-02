#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CHARGE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CHARGE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using electric_charge_t = decltype(second<> * ampere<>);

inline constexpr electric_charge_t coulomb{}; 
}

namespace mitama {
template <> struct abbreviation<si::electric_charge_t> { static constexpr char str[] = "C"; };
}
#endif
