#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_DYNAMIC_VISCOSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_DYNAMIC_VISCOSITY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

#include "pressure.hpp"

namespace mitama::systems::si {
template<class> struct dynamic_viscosity_synonym{};
using dynamic_viscosity_t = make_synonym_t<dynamic_viscosity_synonym, decltype(pascal * seconds)>;

inline constexpr dynamic_viscosity_t dynamic_viscosity{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::dynamic_viscosity_t> { static constexpr char str[] = "Pa s"; };
}
#endif
