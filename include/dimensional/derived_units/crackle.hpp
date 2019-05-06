#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CRACKLE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CRACKLE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct crackle_repr{};
using crackle_t = make_synonym_t<crackle_repr, decltype(meters * second<-5>)>;

inline constexpr crackle_t crackle{};
using crackle_r = make_refinement_symbol_t<crackle_t>;
}

namespace mitama {
template <> struct abbreviation<si::crackle_t> { static constexpr char str[] = "m/s^5"; };
}

#endif
