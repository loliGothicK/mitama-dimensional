#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTIVITY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

#include "resistance.hpp"

namespace mitama::systems::si {
template<class> struct resistivity_synonym{};
using resistivity_t = make_synonym_t<resistivity_synonym, decltype(ohm * meter<>)>;

inline constexpr resistivity_t resistivity{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::resistivity_t> { static constexpr char str[] = "Ω m"; };
}
#endif
