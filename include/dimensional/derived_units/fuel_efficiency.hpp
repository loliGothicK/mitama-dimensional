#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FUEL_EFFICIENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_FUEL_EFFICIENCY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct fuel_efficiency_synonym{};
using fuel_efficiency_t = make_synonym_t<fuel_efficiency_synonym, decltype(meter<-2>)>;

inline constexpr fuel_efficiency_t fuel_efficiency{};
using fuel_efficiency_r = make_refinement_symbol_t<fuel_efficiency_t>;
}

namespace mitama {
template <> struct abbreviation<si::fuel_efficiency_t> { static constexpr char str[] = "m/m^3"; };
}

#endif
