#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct power_synonym{};
using power_t = make_synonym_t<power_synonym, decltype(kilogram<> * meter<2> * second<-3>)>;

inline constexpr power_t watt{};
using power_r = make_refinement_symbol_t<power_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::power_t> { static constexpr char str[] = "W"; };
}

#endif
