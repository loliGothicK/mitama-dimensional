#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SNAP_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SNAP_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct snap_synonym{};
using snap_t = make_synonym_t<snap_synonym, decltype(meters * second<-4>)>;

inline constexpr snap_t snap{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::snap_t> { static constexpr char str[] = "m/s^4"; };
}

#endif
