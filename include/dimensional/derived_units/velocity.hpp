#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_VELOCITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_VELOCITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
template<class> struct velocity_repr{};
using velocity_t = make_synonym_t<velocity_repr, decltype(meters / seconds)>;

inline constexpr velocity_t velocity{};
}

namespace mitama {
template <> struct abbreviation<si::velocity_t> { static constexpr char str[] = "m/s"; };
}

#endif
