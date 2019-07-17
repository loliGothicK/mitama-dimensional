#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ACCELERATION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ACCELERATION_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct acceleration_synonym{};
using acceleration_t = make_synonym_t<acceleration_synonym, decltype(meters * second<-2>)>;

inline constexpr acceleration_t acceleration{};
using acceleration_r = make_refinement_symbol_t<acceleration_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::acceleration_t> { static constexpr char str[] = "m/s^2"; };
}

#endif
