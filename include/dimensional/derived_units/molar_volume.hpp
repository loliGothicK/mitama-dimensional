#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_VOLUME_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_VOLUME_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct molar_volume_repr{};
using molar_volume_t = make_synonym_t<molar_volume_repr, decltype(meter<3> / mol<>)>;

inline constexpr molar_volume_t molar_volume{};
using molar_volume_r = make_refinement_symbol_t<molar_volume_t>;
}

namespace mitama {
template <> struct abbreviation<si::molar_volume_t> { static constexpr char str[] = "m^3/mol"; };
}
#endif
