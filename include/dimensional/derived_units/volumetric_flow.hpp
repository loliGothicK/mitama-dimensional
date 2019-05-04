#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLUMETRIC_FLOW_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLUMETRIC_FLOW_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct volumetric_flow_repr{};
using volumetric_flow_t = make_synonym_t<volumetric_flow_repr, decltype(meter<3> / second<>)>;

inline constexpr volumetric_flow_t volumetric_flow{};
using volumetric_flow_r = make_refiment_symbol_t<volumetric_flow_t>;
}
namespace mitama {
template <> struct abbreviation<si::volumetric_flow_t> { static constexpr char str[] = "m^3/s"; };
}

#endif
