#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ILLUMINANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ILLUMINANCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct illuminance_repr{};
using illuminance_t = make_synonym_t<illuminance_repr, decltype(meter<-2> * candela<>)>;

inline constexpr illuminance_t lux{};
using illuminance_r = make_refinement_symbol_t<illuminance_t>;
}

namespace mitama {
template <> struct abbreviation<si::illuminance_t> { static constexpr char str[] = "lx"; };
}
#endif
