#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_STIFFNESS_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_STIFFNESS_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "./force.hpp"

namespace mitama::si {
template<class> struct stiffness_repr{};
using stiffness_t = make_synonym_t<stiffness_repr, decltype(newton / meter<>)>;

inline constexpr stiffness_t stiffness{};
using stiffness_r = make_refiment_symbol_t<stiffness_t>;
}

namespace mitama {
template <> struct abbreviation<si::stiffness_t> { static constexpr char str[] = "N/m"; };
}
#endif
