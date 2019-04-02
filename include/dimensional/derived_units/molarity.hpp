#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLARITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLARITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using molarity_t = decltype(mol<> / meter<3>);

inline constexpr molarity_t molarity{};
}

namespace mitama {
template <> struct abbreviation<si::molarity_t> { static constexpr char str[] = "mol/m^3"; };
}
#endif
