#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_WAVENUMBER_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_WAVENUMBER_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
using wavenumber_t = reciprocal_t<meter_t>;

inline constexpr wavenumber_t wavenumber{};

}

#endif
