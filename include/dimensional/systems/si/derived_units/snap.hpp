#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SNAP_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SNAP_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct snap_synonym{};
using snap_t = make_synonym_t<snap_synonym, decltype(meters * second<-4>)>;

inline constexpr snap_t snap{};
using snap_r = make_refinement_symbol_t<snap_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::snap_t> { static constexpr char str[] = "m/s^4"; };
}

#endif
