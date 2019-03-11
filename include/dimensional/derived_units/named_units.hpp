#pragma once
#include "../si/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama {
using velocity_t = decltype(meters / seconds);
using accelaration_t = decltype(meters * second<-2>);
using jerk_t = decltype(meters * second<-3>);
using snap_t = decltype(meters * second<-4>);
using crackle_t = decltype(meters * second<-5>);
using pop_t = decltype(meters * second<-6>);

using minute_t = scaled_unit_t<second_t, std::ratio<60>>;
using hour_t = scaled_unit_t<minute_t, std::ratio<60>>;
using day_t = scaled_unit_t<hour_t, std::ratio<24>>;
}

// dimensionless
namespace mitama {
struct angle { using is_base_dimension = void; };
using radian_t = make_unit_t<angle>;
inline constexpr radian_t radian{};
template <> struct symbol_<angle> { static constexpr char str[] = "rad"; };

struct solid_angle { using is_base_dimension = void; };
using steradian_t = make_unit_t<solid_angle>;
inline constexpr steradian_t steradian{};
template <> struct symbol_<solid_angle> { static constexpr char str[] = "sr"; };

struct dose_equivalence { using is_base_dimension = void; };
using sievert_t = make_unit_t<dose_equivalence>;
inline constexpr sievert_t sievert{};
template <> struct symbol_<dose_equivalence> { static constexpr char str[] = "Sv"; };

struct activity { using is_base_dimension = void; };
using activity_t = make_unit_t<activity>;
inline constexpr activity_t becquerel{};
template <> struct symbol_<activity> { static constexpr char str[] = "Bq"; };

}

namespace mitama {
using frequency_t = powered_t<second_t, -1>;
using force_t = decltype(kilogram<> * meter<> * second<-2>);
using momentum_t = decltype(kilogram<> * meter<> * second<-1>);
using pressure_t = decltype(kilogram<> * meter<-1> * second<-2>);
using energy_t = decltype(kilogram<> * meter<2> * second<-2>);
using power_t = decltype(kilogram<> * meter<2> * second<-3>);
using electric_charge_t = decltype(second<> * ampere<>);
using electric_potential_t = decltype(kilogram<> * meter<2> * second<-3> * ampere<-1>);
using capacitance_t = decltype(kilogram<-1> * meter<-2> * second<4> * ampere<2>);
using resistance_t = decltype(kilogram<> * meter<2> * second<-3> * ampere<-2>);
using conductance_t = decltype(kilogram<-1> * meter<-2> * second<3> * ampere<2>);
using magnetic_flux_t = decltype(kilogram<> * meter<2> * second<-2> * ampere<-1>);
using magnetic_flux_density_t = decltype(kilogram<> * second<-2> * ampere<-1>);
using inductance_t = decltype(kilogram<> * meter<2> * second<-2> * ampere<-2>);
using luminous_flux_t = decltype(candela<> * steradian);
using illuminance_t = decltype(meter<-2> * candela<>);
using absorbed_dose_t = decltype(meter<2> * second<-2>);
using catalytic_activity_t = decltype(second<-1> * mol<>);


inline constexpr frequency_t hertz{}; 
inline constexpr force_t newton{}; 
inline constexpr momentum_t momentum{};
inline constexpr pressure_t pascal{}; 
inline constexpr energy_t joule{}; 
inline constexpr power_t watt{}; 
inline constexpr electric_charge_t coulomb{}; 
inline constexpr electric_potential_t volt{}; 
inline constexpr capacitance_t farad{}; 
inline constexpr resistance_t ohm{}; 
inline constexpr conductance_t siemens{}; 
inline constexpr magnetic_flux_t weber{}; 
inline constexpr magnetic_flux_density_t tesla{}; 
inline constexpr inductance_t henry{}; 
inline constexpr luminous_flux_t lumen{}; 
inline constexpr illuminance_t lux{}; 
inline constexpr absorbed_dose_t gray{}; 
inline constexpr catalytic_activity_t katal{}; 


template <> struct abbreviation<frequency_t> { static constexpr char str[] = "Hz"; };
template <> struct abbreviation<force_t> { static constexpr char str[] = "N"; };
template <> struct abbreviation<pressure_t> { static constexpr char str[] = "Pa"; };
template <> struct abbreviation<energy_t> { static constexpr char str[] = "J"; };
template <> struct abbreviation<power_t> { static constexpr char str[] = "W"; };
template <> struct abbreviation<electric_charge_t> { static constexpr char str[] = "C"; };
template <> struct abbreviation<electric_potential_t> { static constexpr char str[] = "V"; };
template <> struct abbreviation<capacitance_t> { static constexpr char str[] = "F"; };
template <> struct abbreviation<resistance_t> { static constexpr char str[] = "Ω"; };
template <> struct abbreviation<conductance_t> { static constexpr char str[] = "S"; };
template <> struct abbreviation<magnetic_flux_t> { static constexpr char str[] = "Wb"; };
template <> struct abbreviation<magnetic_flux_density_t> { static constexpr char str[] = "T"; };
template <> struct abbreviation<inductance_t> { static constexpr char str[] = "H"; };
template <> struct abbreviation<luminous_flux_t> { static constexpr char str[] = "lm"; };
template <> struct abbreviation<illuminance_t> { static constexpr char str[] = "lx"; };
template <> struct abbreviation<absorbed_dose_t> { static constexpr char str[] = "Gy"; };
template <> struct abbreviation<catalytic_activity_t> { static constexpr char str[] = "kat"; };
}

namespace mitama {
using viscosity_t = decltype(pascal * seconds);
using torque_t = decltype(newton * meters);
using surf_tension_t = decltype(newton * meter<-2>);
using angular_velocity_t = decltype(radian / seconds);
using angular_accelaration_t = decltype(radian / second<2>);
using heat_flux_t = decltype(watt * meter<-2>);
using heat_capacity_t = decltype(joule / kelvins);
using entropy_t = decltype(joule / kelvins);
using specific_heat_capacity_t = decltype( joule / (kilograms * kelvins) );
using thermal_conductivity_t = decltype( watt / (meters * kelvins) );
using electric_field_strength_t = decltype(volt / meters);
using charge_density_t = decltype(coulomb / meter<3>);
using electric_flux_density_t = decltype(coulomb / meter<2>);
using permittivity_t = decltype(farad / meter<>);
using permeability_t = decltype(henry / meter<>);
using exposure_t = decltype(coulomb / kilogram<>);


inline constexpr viscosity_t viscosity{};
inline constexpr torque_t torque{};
inline constexpr surf_tension_t surf_tension{};
inline constexpr angular_velocity_t angular_velocity{};
inline constexpr angular_accelaration_t angular_accelaration{};
inline constexpr heat_flux_t heat_flux{};
inline constexpr heat_capacity_t heat_capacity{};
inline constexpr entropy_t entropy{};
inline constexpr specific_heat_capacity_t specific_heat_capacity{};
inline constexpr thermal_conductivity_t thermal_conductivity{};
inline constexpr electric_field_strength_t electric_field_strength{};
inline constexpr charge_density_t charge_density{};
inline constexpr electric_flux_density_t electric_flux_density{};
inline constexpr permittivity_t permittivity{};
inline constexpr permeability_t permeability{};
inline constexpr exposure_t exposure{};


template <> struct abbreviation<viscosity_t> { static constexpr char str[] = "Pa·s"; };
template <> struct abbreviation<angular_velocity_t> { static constexpr char str[] = "rad/s"; };
template <> struct abbreviation<angular_accelaration_t> { static constexpr char str[] = "rad/s^2"; };
template <> struct abbreviation<heat_flux_t> { static constexpr char str[] = "W/m^2"; };
template <> struct abbreviation<heat_capacity_t> { static constexpr char str[] = "J/K"; };
template <> struct abbreviation<specific_heat_capacity_t> { static constexpr char str[] = "J/(kg·K)"; };
template <> struct abbreviation<thermal_conductivity_t> { static constexpr char str[] = "W/(m·K)"; };
template <> struct abbreviation<electric_field_strength_t> { static constexpr char str[] = "V/m"; };
template <> struct abbreviation<charge_density_t> { static constexpr char str[] = "C/m^3"; };
template <> struct abbreviation<electric_flux_density_t> { static constexpr char str[] = "C/m^2"; };
template <> struct abbreviation<permittivity_t> { static constexpr char str[] = "F/m"; };
template <> struct abbreviation<permeability_t> { static constexpr char str[] = "H/m"; };
template <> struct abbreviation<exposure_t> { static constexpr char str[] = "C/kg"; };
}
