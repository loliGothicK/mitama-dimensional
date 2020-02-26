#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_TEMPERATURE_GRADIENT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_TEMPERATURE_GRADIENT_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct temperature_gradient_synonym{};
using temperature_gradient_t = make_synonym_t<temperature_gradient_synonym, decltype(kelvin<> / meter<>)>;

inline constexpr temperature_gradient_t temperature_gradient{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::temperature_gradient_t> { static constexpr char str[] = "K/m"; };
}

#endif
