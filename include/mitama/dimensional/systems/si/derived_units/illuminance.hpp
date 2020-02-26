#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ILLUMINANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ILLUMINANCE_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct illuminance_synonym{};
using illuminance_t = make_synonym_t<illuminance_synonym, decltype(meter<-2> * candela<>)>;

inline constexpr illuminance_t lux{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::illuminance_t> { static constexpr char str[] = "lx"; };
}
#endif
