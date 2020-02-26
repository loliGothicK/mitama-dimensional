#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRON_MOBILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRON_MOBILITY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

#include "voltage.hpp"

namespace mitama::systems::si {
template<class> struct electron_mobility_synonym{};
using electron_mobility_t = make_synonym_t<electron_mobility_synonym, decltype( meter<2> * volt<-1> * second<-1> )>;

inline constexpr electron_mobility_t electron_mobility{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::electron_mobility_t> { static constexpr char str[] = "m^2/(V s)"; };
}
#endif
