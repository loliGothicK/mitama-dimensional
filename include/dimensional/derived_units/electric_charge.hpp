#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CHARGE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CHARGE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct electric_charge_repr{};
using electric_charge_t = make_synonym_t<electric_charge_repr, decltype(second<> * ampere<>)>;

inline constexpr electric_charge_t coulomb{};
using electric_charge_r = make_refiment_symbol_t<electric_charge_t>;
}

namespace mitama {
template <> struct abbreviation<si::electric_charge_t> { static constexpr char str[] = "C"; };
}
#endif
