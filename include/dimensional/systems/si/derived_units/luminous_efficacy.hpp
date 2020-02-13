#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_EFFICACY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_EFFICACY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

#include "power.hpp"
#include "luminous_flux.hpp"

namespace mitama::systems::si {
template<class> struct luminous_efficacy_synonym{};
using luminous_efficacy_t = make_synonym_t<luminous_efficacy_synonym, decltype(lumen / watt)>;

inline constexpr luminous_efficacy_t luminous_efficacy{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::luminous_efficacy_t> { static constexpr char str[] = "lm/W"; };
}
#endif
