#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ABSORBED_DOSE_RATE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ABSORBED_DOSE_RATE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "absorbed_dose.hpp"

namespace mitama::si {
template < class > struct absorbed_dose_rate_repr{};

using absorbed_dose_rate_t = make_synonym_t<absorbed_dose_rate_repr, decltype(gray / second<>)>;

inline constexpr absorbed_dose_rate_t absorbed_dose_rate{};
}

namespace mitama {
template <> struct abbreviation<si::absorbed_dose_rate_t> { static constexpr char str[] = "Gy/s"; };
}
#endif
