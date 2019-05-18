#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ILLUMINANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ILLUMINANCE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct illuminance_synonym{};
using illuminance_t = make_synonym_t<illuminance_synonym, decltype(meter<-2> * candela<>)>;

inline constexpr illuminance_t lux{};
using illuminance_r = make_refinement_symbol_t<illuminance_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::illuminance_t> { static constexpr char str[] = "lx"; };
}
#endif
