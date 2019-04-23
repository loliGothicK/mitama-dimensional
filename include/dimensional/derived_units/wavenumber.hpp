#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_WAVENUMBER_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_WAVENUMBER_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
using wavenumber_t = reciprocal_t<meter_t>;

inline constexpr wavenumber_t wavenumber{};
using wavenumber_r = make_refiment_symbol_t<wavenumber_t>;
}

#endif
