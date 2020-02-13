#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMEABILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMEABILITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

#include "inductance.hpp"

namespace mitama::systems::si {
template<class> struct permeability_synonym{};
using permeability_t = make_synonym_t<permeability_synonym, decltype(henry / meter<>)>;

inline constexpr permeability_t permeability{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::permeability_t> { static constexpr char str[] = "H/m"; };
}
#endif
