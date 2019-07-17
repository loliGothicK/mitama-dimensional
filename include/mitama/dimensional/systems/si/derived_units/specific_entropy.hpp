#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ENTROPY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ENTROPY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>
#include "energy.hpp"


namespace mitama::systems::si {
template<class> struct specific_entropy_synonym{};
using specific_entropy_t = make_synonym_t<specific_entropy_synonym, decltype( joule / (kilograms * kelvins) )>;

inline constexpr specific_entropy_t specific_entropy{};
using specific_entropy_r = make_refinement_symbol_t<specific_entropy_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_HEAT_CAPACITY_HPP
namespace mitama {
template <> struct  abbreviation_<systems::si::specific_entropy_t> { static constexpr char str[] = "J/(K⋅kg)"; };
}
#endif

#endif
