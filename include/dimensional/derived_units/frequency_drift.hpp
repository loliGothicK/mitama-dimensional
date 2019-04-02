#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FREQUENCY_DRIFT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_FREQUENCY_DRIFT_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using frequency_drift_t = std::decay_t<decltype(second<-2>)>;

inline constexpr frequency_drift_t frequency_drift{};
}

namespace mitama {
template <> struct abbreviation<si::frequency_drift_t> { static constexpr char str[] = "Hz/s"; };
}

#endif
