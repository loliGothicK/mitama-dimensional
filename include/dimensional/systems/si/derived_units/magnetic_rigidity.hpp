#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_RIGIDITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_RIGIDITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

#include "magnetic_flux_density.hpp"

namespace mitama::systems::si {
template<class> struct magnetic_rigidity_synonym{};
using magnetic_rigidity_t = make_synonym_t<magnetic_rigidity_synonym, decltype(tesla * meter<>)>;

inline constexpr magnetic_rigidity_t magnetic_rigidity{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::magnetic_rigidity_t> { static constexpr char str[] = "T m"; };
}
#endif
