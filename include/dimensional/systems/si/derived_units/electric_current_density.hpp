#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CURRENT_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CURRENT_DENSITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct electric_current_density_synonym{};
using electric_current_density_t = make_synonym_t<electric_current_density_synonym, decltype(ampere<> / meter<2>)>;

inline constexpr electric_current_density_t electric_current_density{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::electric_current_density_t> { static constexpr char str[] = "A/m^2"; };
}
#endif
