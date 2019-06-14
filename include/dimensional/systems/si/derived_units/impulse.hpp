#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPULSE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPULSE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct impulse_synonym{};
using impulse_t = make_synonym_t<impulse_synonym, decltype(meter<> * kilogram<> * second<-1>)>;

inline constexpr impulse_t impulse{};
using impulse_r = make_refinement_symbol_t<impulse_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENTUM_HPP
namespace mitama {
template <> struct  abbreviation_<systems::si::impulse_t> { static constexpr char str[] = "N s"; };
}
#endif

#endif
