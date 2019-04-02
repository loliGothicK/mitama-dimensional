#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CATALYTIC_EFFICIENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CATALYTIC_EFFICIENCY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using catalytic_efficiency_t = decltype(meter<3> / (mol<> * second<>));

inline constexpr catalytic_efficiency_t catalytic_efficiency{};
}

namespace mitama {
template <> struct abbreviation<si::catalytic_efficiency_t> { static constexpr char str[] = "m^3/(mol·s)"; };
}
#endif
