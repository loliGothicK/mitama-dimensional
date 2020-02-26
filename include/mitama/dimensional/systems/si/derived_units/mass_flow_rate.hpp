#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MASS_FLOW_RATE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MASS_FLOW_RATE_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct mass_flow_rate_synonym{};
using mass_flow_rate_t = make_synonym_t<mass_flow_rate_synonym, decltype(kilogram<> / second<>)>;

inline constexpr mass_flow_rate_t mass_flow_rate{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::mass_flow_rate_t> { static constexpr char str[] = "kg/s"; };
}

#endif
