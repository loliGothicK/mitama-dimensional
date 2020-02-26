#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANCE_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

#include "power.hpp"
#include "solid_angle.hpp"

namespace mitama::systems::si {
template<class> struct radiance_synonym{};
using radiance_t = make_synonym_t<radiance_synonym, decltype( watt / steradian * meter<-2> )>;

inline constexpr radiance_t radiance{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::radiance_t> { static constexpr char str[] = "W/(sr m^2)"; };
}
#endif
