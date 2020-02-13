#ifndef MITAMA_DIMENSIONAL_SYSTEMS_SI_BASE_UNITS_LITERALS_METER_LITERALS_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_SI_BASE_UNITS_LITERALS_METER_LITERALS_HPP
#include <dimensional/systems/si/quantity.hpp>

namespace mitama::literals {
inline namespace units_literals {
inline namespace si_literals {
inline namespace length_literals {
    inline constexpr auto
    operator"" _m(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::meter_t, long double>{value}; }

    inline constexpr auto
    operator"" _dm(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::decimeter_t, long double>{value}; }

    inline constexpr auto
    operator"" _cm(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::centimeter_t, long double>{value}; }

    inline constexpr auto
    operator"" _mm(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::millimeter_t, long double>{value}; }

    inline constexpr auto
    operator"" _um(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::micrometer_t, long double>{value}; }

    inline constexpr auto
    operator"" _nm(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::nanometer_t, long double>{value}; }

    inline constexpr auto
    operator"" _pm(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::picometer_t, long double>{value}; }

    inline constexpr auto
    operator"" _km(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::kilometer_t, long double>{value}; }

    inline constexpr auto
    operator"" _Mm(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::megameter_t, long double>{value}; }

}}}}
#endif
