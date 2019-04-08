#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLARITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLARITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
template<class> struct molarity_repr{};
using molarity_t = make_synonym_t<molarity_repr, decltype(mol<> / meter<3>)>;

inline constexpr molarity_t molarity{};
}

namespace mitama {
template <> struct abbreviation<si::molarity_t> { static constexpr char str[] = "mol/m^3"; };
}
#endif
