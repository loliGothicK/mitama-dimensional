#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CATALYTIC_EFFICIENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CATALYTIC_EFFICIENCY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct catalytic_efficiency_synonym{};
using catalytic_efficiency_t = make_synonym_t<catalytic_efficiency_synonym, decltype(meter<3> / (mol<> * second<>))>;

inline constexpr catalytic_efficiency_t catalytic_efficiency{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::catalytic_efficiency_t> { static constexpr char str[] = "m^3/(mol s)"; };
}
#endif
