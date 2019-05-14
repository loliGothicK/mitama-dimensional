#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ABSORBED_DOSE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ABSORBED_DOSE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct absorbed_dose_synonym{};
using absorbed_dose_t = make_synonym_t<absorbed_dose_synonym, decltype(meter<2> * second<-2>)>;

inline constexpr absorbed_dose_t gray{};
using absorbed_dose_r = make_refinement_symbol_t<absorbed_dose_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::absorbed_dose_t> { static constexpr char str[] = "Gy"; };
}
#endif
