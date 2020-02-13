#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANT_EXPOSURE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANT_EXPOSURE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

#include "energy.hpp"

namespace mitama::systems::si {
template<class> struct radiant_exposure_synonym{};
using radiant_exposure_t = make_synonym_t<radiant_exposure_synonym, decltype(joule / meter<2>)>;

inline constexpr radiant_exposure_t radiant_exposure{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::radiant_exposure_t> { static constexpr char str[] = "J/m^2"; };
}
#endif
