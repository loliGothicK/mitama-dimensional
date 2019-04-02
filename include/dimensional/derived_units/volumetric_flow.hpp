#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLUMETRIC_FLOW_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLUMETRIC_FLOW_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using volumetric_flow_t = decltype(meter<3> / second<>);

inline constexpr volumetric_flow_t volumetric_flow{};
}
namespace mitama {
template <> struct abbreviation<si::volumetric_flow_t> { static constexpr char str[] = "m^3/s"; };
}

#endif
