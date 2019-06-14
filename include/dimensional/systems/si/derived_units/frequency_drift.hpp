#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FREQUENCY_DRIFT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_FREQUENCY_DRIFT_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
using frequency_drift_t = std::decay_t<decltype(second<-2>)>;

inline constexpr frequency_drift_t frequency_drift{};
using frequency_drift_r = make_refinement_symbol_t<frequency_drift_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::frequency_drift_t> { static constexpr char str[] = "Hz/s"; };
}

#endif
