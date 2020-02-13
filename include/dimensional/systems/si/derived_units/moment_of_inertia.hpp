#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENT_OF_INERTIA_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENT_OF_INERTIA_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct moment_of_inertia_synonym{};
using moment_of_inertia_t = make_synonym_t<moment_of_inertia_synonym, decltype(kilogram<> * meter<2>)>;

inline constexpr moment_of_inertia_t moment_of_inertia{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::moment_of_inertia_t> { static constexpr char str[] = "kg m^2"; };
}

#endif
