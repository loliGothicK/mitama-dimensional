#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLUMETRIC_FLOW_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLUMETRIC_FLOW_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct volumetric_flow_synonym{};
using volumetric_flow_t = make_synonym_t<volumetric_flow_synonym, decltype(meter<3> / second<>)>;

inline constexpr volumetric_flow_t volumetric_flow{};

}
namespace mitama {
template <> struct  abbreviation_<systems::si::volumetric_flow_t> { static constexpr char str[] = "m^3/s"; };
}

#endif
