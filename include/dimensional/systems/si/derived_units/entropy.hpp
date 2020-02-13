#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ENTROPY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ENTROPY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

#include "energy.hpp"

namespace mitama::systems::si {
template<class> struct entropy_synonym{};
using entropy_t = make_synonym_t<entropy_synonym, decltype(joule / kelvins)>;

inline constexpr entropy_t entropy{};

}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_CAPACITY_HPP
namespace mitama {
template <> struct  abbreviation_<systems::si::entropy_t> { static constexpr char str[] = "J/K"; };
}
#endif

#endif
