#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CRACKLE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CRACKLE_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct crackle_synonym{};
using crackle_t = make_synonym_t<crackle_synonym, decltype(meters * second<-5>)>;

inline constexpr crackle_t crackle{};
using crackle_r = make_refinement_symbol_t<crackle_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::crackle_t> { static constexpr char str[] = "m/s^5"; };
}

#endif
