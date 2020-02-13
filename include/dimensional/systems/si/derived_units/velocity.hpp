#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_VELOCITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_VELOCITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct velocity_synonym{};
using velocity_t = make_synonym_t<velocity_synonym, decltype(meters / seconds)>;

inline constexpr velocity_t velocity{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::velocity_t> { static constexpr char str[] = "m/s"; };
}

#endif
