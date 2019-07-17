#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLUME_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLUME_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>


namespace mitama::systems::si {
using volume_t = powered_t<meter_t, 3>;

inline constexpr volume_t volume{};
using volume_r = make_refinement_symbol_t<volume_t>;
}

#endif
