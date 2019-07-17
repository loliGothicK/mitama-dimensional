#ifndef MITAMA_DIMENSIONAL_SI_BASE_UNITS_FWD_HPP
#define MITAMA_DIMENSIONAL_SI_BASE_UNITS_FWD_HPP
#include <mitama/dimensional/systems/si/base_dimension/electric_current.hpp>
#include <mitama/dimensional/systems/si/base_dimension/luminous_intensity.hpp>
#include <mitama/dimensional/systems/si/base_dimension/thermodynamic_temperature.hpp>
#include <mitama/dimensional/systems/si/base_dimension/mass.hpp>
#include <mitama/dimensional/systems/si/base_dimension/length.hpp>
#include <mitama/dimensional/systems/si/base_dimension/amount_of_substance.hpp>
#include <mitama/dimensional/systems/si/base_dimension/time.hpp>
#include <mitama/dimensional/units.hpp>
#include <mitama/dimensional/system.hpp>

namespace mitama::systems::si {
using ampere_base_unit = base_units<electric_current, 0>;
using candela_base_unit = base_units<luminous_intensity, 0>;
using kelvin_base_unit = base_units<thermodynamic_temperature, 0>;
using kilogram_base_unit = base_units<mass, 0>;
using meter_base_unit = base_units<length, 0>;
using metre_base_unit = base_units<length, 0>;
using mole_base_unit = base_units<amount_of_substance, 0>;
using second_base_unit = base_units<time, 0>;

using system
    = ::mitama::system<
        ampere_base_unit,
        candela_base_unit,
        kelvin_base_unit,
        kilogram_base_unit,
        meter_base_unit,
        mole_base_unit,
        second_base_unit
    >;
}

#endif
