#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POP_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_POP_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct pop_synonym{};
using pop_t = make_synonym_t<pop_synonym, decltype(meters * second<-6>)>;

inline constexpr pop_t pop{};
using pop_r = make_refinement_symbol_t<pop_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::pop_t> { static constexpr char str[] = "m/s^6"; };
}

#endif
