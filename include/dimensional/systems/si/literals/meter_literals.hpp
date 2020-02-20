#ifndef MITAMA_DIMENSIONAL_SYSTEMS_SI_BASE_UNITS_LITERALS_METER_LITERALS_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_SI_BASE_UNITS_LITERALS_METER_LITERALS_HPP
#include <dimensional/systems/si/quantity.hpp>

namespace mitama::literals {
inline namespace units_literals {
inline namespace si_literals {
inline namespace length_literals {
namespace long_double_literals {
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
}
inline namespace double_literals {
    inline constexpr auto
    operator"" _m(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::meter_t, double>{value}; }

    inline constexpr auto
    operator"" _dm(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::decimeter_t, double>{value}; }

    inline constexpr auto
    operator"" _cm(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::centimeter_t, double>{value}; }

    inline constexpr auto
    operator"" _mm(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::millimeter_t, double>{value}; }

    inline constexpr auto
    operator"" _um(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::micrometer_t, double>{value}; }

    inline constexpr auto
    operator"" _nm(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::nanometer_t, double>{value}; }

    inline constexpr auto
    operator"" _pm(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::picometer_t, double>{value}; }

    inline constexpr auto
    operator"" _km(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::kilometer_t, double>{value}; }

    inline constexpr auto
    operator"" _Mm(long double value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::megameter_t, double>{value}; }
}

namespace unsigned_long_long_literals {
    inline constexpr auto
    operator"" _m(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::meter_t, unsigned long long>{value}; }

    inline constexpr auto
    operator"" _dm(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::decimeter_t, unsigned long long>{value}; }

    inline constexpr auto
    operator"" _cm(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::centimeter_t, unsigned long long>{value}; }

    inline constexpr auto
    operator"" _mm(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::millimeter_t, unsigned long long>{value}; }

    inline constexpr auto
    operator"" _um(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::micrometer_t, unsigned long long>{value}; }

    inline constexpr auto
    operator"" _nm(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::nanometer_t, unsigned long long>{value}; }

    inline constexpr auto
    operator"" _pm(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::picometer_t, unsigned long long>{value}; }

    inline constexpr auto
    operator"" _km(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::kilometer_t, unsigned long long>{value}; }

    inline constexpr auto
    operator"" _Mm(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::megameter_t, unsigned long long>{value}; }
}

inline namespace int_literals {
    inline constexpr auto
    operator"" _m(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::meter_t, int>{value}; }

    inline constexpr auto
    operator"" _dm(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::decimeter_t, int>{value}; }

    inline constexpr auto
    operator"" _cm(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::centimeter_t, int>{value}; }

    inline constexpr auto
    operator"" _mm(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::millimeter_t, int>{value}; }

    inline constexpr auto
    operator"" _um(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::micrometer_t, int>{value}; }

    inline constexpr auto
    operator"" _nm(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::nanometer_t, int>{value}; }

    inline constexpr auto
    operator"" _pm(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::picometer_t, int>{value}; }

    inline constexpr auto
    operator"" _km(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::kilometer_t, int>{value}; }

    inline constexpr auto
    operator"" _Mm(unsigned long long value)
    { return mitama::systems::si::quantity_t<mitama::systems::si::megameter_t, int>{value}; }
}

}}}}
#endif
