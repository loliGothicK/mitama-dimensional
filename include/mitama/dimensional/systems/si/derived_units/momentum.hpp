#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENTUM_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENTUM_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct momentum_synonym{};
using momentum_t = make_synonym_t<momentum_synonym, decltype(meter<> * kilogram<> * second<-1>)>;

inline constexpr momentum_t momentum{};
using momentum_r = make_refinement_symbol_t<momentum_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPULSE_HPP
namespace mitama {
template <> struct  abbreviation_<systems::si::momentum_t> { static constexpr char str[] = "N s"; };
}
#endif

#endif
