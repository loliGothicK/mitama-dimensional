#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct power_synonym{};
using power_t = make_synonym_t<power_synonym, decltype(kilogram<> * meter<2> * second<-3>)>;

inline constexpr power_t watt{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::power_t> { static constexpr char str[] = "W"; };
}

#endif
