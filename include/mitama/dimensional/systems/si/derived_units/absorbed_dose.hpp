#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ABSORBED_DOSE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ABSORBED_DOSE_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct absorbed_dose_synonym{};
using absorbed_dose_t = make_synonym_t<absorbed_dose_synonym, decltype(meter<2> * second<-2>)>;

inline constexpr absorbed_dose_t gray{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::absorbed_dose_t> { static constexpr char str[] = "Gy"; };
}
#endif
