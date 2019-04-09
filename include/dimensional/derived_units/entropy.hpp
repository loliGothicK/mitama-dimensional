#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ENTROPY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ENTROPY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "energy.hpp"

namespace mitama::si {
template<class> struct entropy_repr{};
using entropy_t = make_synonym_t<entropy_repr, decltype(joule / kelvins)>;

inline constexpr entropy_t entropy{};
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_CAPACITY_HPP
namespace mitama {
template <> struct abbreviation<si::entropy_t> { static constexpr char str[] = "J/K"; };
}
#endif

#endif
