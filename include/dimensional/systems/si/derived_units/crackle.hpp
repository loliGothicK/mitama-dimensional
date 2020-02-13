#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CRACKLE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CRACKLE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct crackle_synonym{};
using crackle_t = make_synonym_t<crackle_synonym, decltype(meters * second<-5>)>;

inline constexpr crackle_t crackle{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::crackle_t> { static constexpr char str[] = "m/s^5"; };
}

#endif
