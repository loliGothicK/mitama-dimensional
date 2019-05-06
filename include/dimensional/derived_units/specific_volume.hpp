#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_VOLUME_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_VOLUME_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct specific_volume_repr{};
using specific_volume_t = make_synonym_t<specific_volume_repr, decltype(meter<3> / kilogram<>)>;

inline constexpr specific_volume_t specific_volume{};
using specific_volume_r = make_refinement_symbol_t<specific_volume_t>;
}

namespace mitama {
template <> struct abbreviation<si::specific_volume_t> { static constexpr char str[] = "m^3/kg"; };
}

#endif
