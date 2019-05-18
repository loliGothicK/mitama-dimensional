#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_VOLUME_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_VOLUME_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct specific_volume_synonym{};
using specific_volume_t = make_synonym_t<specific_volume_synonym, decltype(meter<3> / kilogram<>)>;

inline constexpr specific_volume_t specific_volume{};
using specific_volume_r = make_refinement_symbol_t<specific_volume_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::specific_volume_t> { static constexpr char str[] = "m^3/kg"; };
}

#endif
