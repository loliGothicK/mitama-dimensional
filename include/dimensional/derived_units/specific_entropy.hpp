#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ENTROPY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ENTROPY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "energy.hpp"


namespace mitama::si {
template<class> struct specific_entropy_repr{};
using specific_entropy_t = make_synonym_t<specific_entropy_repr, decltype( joule / (kilograms * kelvins) )>;

inline constexpr specific_entropy_t specific_entropy{};
using specific_entropy_r = make_refiment_symbol_t<specific_entropy_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_HEAT_CAPACITY_HPP
namespace mitama {
template <> struct abbreviation<si::specific_entropy_t> { static constexpr char str[] = "J/(K⋅kg)"; };
}
#endif

#endif
