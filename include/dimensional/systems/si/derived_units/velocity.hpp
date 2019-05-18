#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_VELOCITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_VELOCITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct velocity_synonym{};
using velocity_t = make_synonym_t<velocity_synonym, decltype(meters / seconds)>;

inline constexpr velocity_t velocity{};
using velocity_r = make_refinement_symbol_t<velocity_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::velocity_t> { static constexpr char str[] = "m/s"; };
}

#endif
