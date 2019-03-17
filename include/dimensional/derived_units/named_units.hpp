#pragma once
#include "../si/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


// Table 6
namespace mitama::nonsi {
using hectare_t = powered_t<scaled_unit_t<si::meter_t, std::hecto>, 2>;
inline constexpr hectare_t hectare{};

using litre_t = powered_t<scaled_unit_t<si::meter_t, std::deci>, 3>;
inline constexpr litre_t litre{};
using liter_t = powered_t<scaled_unit_t<si::meter_t, std::deci>, 3>;
inline constexpr liter_t liter{};

using tonne_t = scaled_unit_t<si::kilogram_t, std::ratio<1000>>;
inline constexpr tonne_t tonne{};

using au_t = scaled_unit_t<si::meter_t, std::ratio<149'597'870'700>>;
inline constexpr au_t au{};

using minute_t = scaled_unit_t<si::second_t, std::ratio<60>>;
inline constexpr minute_t minutes{};

using hour_t = scaled_unit_t<minute_t, std::ratio<60>>;
inline constexpr hour_t hours{};

using day_t = scaled_unit_t<hour_t, std::ratio<24>>;
inline constexpr day_t days{};
}

namespace mitama {
template <> struct abbreviation<nonsi::day_t> { static constexpr char str[] = "d"; };
template <> struct abbreviation<nonsi::hour_t> { static constexpr char str[] = "h"; };
template <> struct abbreviation<nonsi::minute_t> { static constexpr char str[] = "m"; };
template <> struct abbreviation<nonsi::au_t> { static constexpr char str[] = "au"; };
template <> struct abbreviation<nonsi::tonne_t> { static constexpr char str[] = "t"; };
template <> struct abbreviation<nonsi::hectare_t> { static constexpr char str[] = "ha"; };
template <> struct abbreviation<nonsi::litre_t> { static constexpr char str[] = "L"; };
}

// Named units derived from SI base units
namespace mitama::si {
struct angle { using is_base_dimension = void; };
using radian_t = make_unit_t<angle>;
inline constexpr radian_t radian{};

struct solid_angle { using is_base_dimension = void; };
using steradian_t = make_unit_t<solid_angle>;
inline constexpr steradian_t steradian{};

struct dose_equivalence { using is_base_dimension = void; };
using sievert_t = make_unit_t<dose_equivalence>;
inline constexpr sievert_t sievert{};

struct activity { using is_base_dimension = void; };
using activity_t = make_unit_t<activity>;
inline constexpr activity_t becquerel{};

using frequency_t = reciprocal_t<second_t>;
inline constexpr frequency_t hertz{}; 

using force_t = decltype(kilogram<> * meter<> * second<-2>);
inline constexpr force_t newton{}; 

using pressure_t = decltype(kilogram<> * meter<-1> * second<-2>);
inline constexpr pressure_t pascal{}; 

using energy_t = decltype(kilogram<> * meter<2> * second<-2>);
inline constexpr energy_t joule{}; 

using power_t = decltype(kilogram<> * meter<2> * second<-3>);
inline constexpr power_t watt{};

using electric_charge_t = decltype(second<> * ampere<>);
inline constexpr electric_charge_t coulomb{}; 

using electric_potential_t = decltype(kilogram<> * meter<2> * second<-3> * ampere<-1>);
template < std::intmax_t N >
inline constexpr powered_t<electric_potential_t, N> volt{}; 

using capacitance_t = decltype(kilogram<-1> * meter<-2> * second<4> * ampere<2>);
inline constexpr capacitance_t farad{}; 

using resistance_t = decltype(kilogram<> * meter<2> * second<-3> * ampere<-2>);
inline constexpr resistance_t ohm{}; 

using conductance_t = decltype(kilogram<-1> * meter<-2> * second<3> * ampere<2>);
inline constexpr conductance_t siemens{}; 

using magnetic_flux_t = decltype(kilogram<> * meter<2> * second<-2> * ampere<-1>);
inline constexpr magnetic_flux_t weber{}; 

using magnetic_flux_density_t = decltype(kilogram<> * second<-2> * ampere<-1>);
inline constexpr magnetic_flux_density_t tesla{}; 

using inductance_t = decltype(kilogram<> * meter<2> * second<-2> * ampere<-2>);
inline constexpr inductance_t henry{}; 

using luminous_flux_t = decltype(candela<> * steradian);
inline constexpr luminous_flux_t lumen{}; 

using illuminance_t = decltype(meter<-2> * candela<>);
inline constexpr illuminance_t lux{}; 

using absorbed_dose_t = decltype(meter<2> * second<-2>);
inline constexpr absorbed_dose_t gray{}; 

using catalytic_activity_t = decltype(second<-1> * mol<>);
inline constexpr catalytic_activity_t katal{}; 
}

namespace mitama {
template <> struct abbreviation<si::catalytic_activity_t> { static constexpr char str[] = "kat"; };
template <> struct abbreviation<si::absorbed_dose_t> { static constexpr char str[] = "Gy"; };
template <> struct abbreviation<si::illuminance_t> { static constexpr char str[] = "lx"; };
template <> struct abbreviation<si::luminous_flux_t> { static constexpr char str[] = "lm"; };
template <> struct abbreviation<si::inductance_t> { static constexpr char str[] = "H"; };
template <> struct abbreviation<si::magnetic_flux_density_t> { static constexpr char str[] = "T"; };
template <> struct abbreviation<si::magnetic_flux_t> { static constexpr char str[] = "Wb"; };
template <> struct abbreviation<si::conductance_t> { static constexpr char str[] = "S"; };
template <> struct abbreviation<si::resistance_t> { static constexpr char str[] = "Ω"; };
template <> struct abbreviation<si::capacitance_t> { static constexpr char str[] = "F"; };
template <> struct abbreviation<si::electric_potential_t> { static constexpr char str[] = "V"; };
template <> struct abbreviation<si::electric_charge_t> { static constexpr char str[] = "C"; };
template <> struct abbreviation<si::power_t> { static constexpr char str[] = "W"; };
template <> struct abbreviation<si::energy_t> { static constexpr char str[] = "J"; };
template <> struct abbreviation<si::pressure_t> { static constexpr char str[] = "Pa"; };
template <> struct abbreviation<si::force_t> { static constexpr char str[] = "N"; };
template <> struct abbreviation<si::frequency_t> { static constexpr char str[] = "Hz"; };
template <> struct symbol_<si::activity> { static constexpr char str[] = "Bq"; };
template <> struct symbol_<si::dose_equivalence> { static constexpr char str[] = "Sv"; };
template <> struct symbol_<si::solid_angle> { static constexpr char str[] = "sr"; };
template <> struct symbol_<si::angle> { static constexpr char str[] = "rad"; };
}

// Kinematic SI derived units
namespace mitama::si {
using velocity_t = decltype(meters / seconds);
inline constexpr velocity_t velocity{};

using speed_t = decltype(kilometers / nonsi::hours);
inline constexpr speed_t speed{};

using accelaration_t = decltype(meters * second<-2>);
inline constexpr accelaration_t accelaration{};

using jerk_t = decltype(meters * second<-3>);
inline constexpr jerk_t jerk{};

using snap_t = decltype(meters * second<-4>);
inline constexpr snap_t snap{};

using crackle_t = decltype(meters * second<-5>);
inline constexpr crackle_t crackle{};

using pop_t = decltype(meters * second<-6>);
inline constexpr pop_t pop{};

using frequency_drift_t = decltype(frequency_t{} / second<>);
inline constexpr frequency_drift_t frequency_drift{};

using volumetric_flow_t = decltype(meter<3> / second<>);
inline constexpr volumetric_flow_t volumetric_flow{};
}

namespace mitama {
template <> struct abbreviation<si::speed_t> { static constexpr char str[] = "km/h"; };
template <> struct abbreviation<si::velocity_t> { static constexpr char str[] = "m/s"; };
}


// Mechanical SI derived units
namespace mitama::si {
using area_t = powered_t<meter_t, 2>;
inline constexpr area_t area{}; 

using volume_t = powered_t<meter_t, 3>;
inline constexpr volume_t volume{}; 

using momentum_t = decltype(meter<> * kilogram<> * second<-1>);
inline constexpr momentum_t momentum{};

using impulse_t = decltype(meter<> * kilogram<> * second<-1>);
inline constexpr impulse_t impulse{};

using torque_t = decltype(newton * meters);
inline constexpr torque_t torque{};

using wavenumber_t = reciprocal_t<meter_t>;
inline constexpr wavenumber_t wavenumber{};

using optical_power_t = reciprocal_t<meter_t>;
inline constexpr optical_power_t optical_power{};

using curvature_t = reciprocal_t<meter_t>;
inline constexpr curvature_t curvature{};

using spatial_frequency_t = reciprocal_t<meter_t>;
inline constexpr spatial_frequency_t spatial_frequency{};

using area_density_t = decltype(meter<-2> * kilogram<>);
inline constexpr area_density_t area_density{};

using density_t = decltype(meter<-3> * kilogram<>);
inline constexpr density_t density{};

using specific_volume_t = reciprocal_t<density_t>;
inline constexpr specific_volume_t specific_volume{};

using action_t = decltype(meter<2> * kilogram<> * second<-1>);
inline constexpr action_t action{};

using specific_energy_t = decltype(joule / kilogram<>);
inline constexpr specific_energy_t specific_energy{};
// duplicates with absobed dose [Gy, m^2/s^2] 
// template <> struct abbreviation<specific_energy_t> { static constexpr char str[] = "J/kg"; };

using energy_density_t = decltype(joule / meter<3>);
inline constexpr energy_density_t energy_density{};
// duplicates with pressure [Pa] 
// template <> struct abbreviation<energy_density_t> { static constexpr char str[] = "J/m^3"; };

using surf_tension_t = decltype(newton / meter<>);
inline constexpr surf_tension_t surf_tension{};

using stiffness_t = decltype(newton / meter<>);
inline constexpr stiffness_t stiffness{};

using heat_flux_density_t = decltype(watt / meter<>);
inline constexpr heat_flux_density_t heat_flux_density{};

using irradiance_t = decltype(watt / meter<>);
inline constexpr irradiance_t irradiance{};

using kinematic_viscosity_t = decltype(meter<2> / second<1>);
inline constexpr kinematic_viscosity_t kinematic_viscosity{};

using thermal_diffusivity_t = decltype(meter<2> / second<1>);
inline constexpr thermal_diffusivity_t thermal_diffusivity{};

using linear_mass_density_t = decltype(meter<-1> * kilogram<>);
inline constexpr linear_mass_density_t linear_mass_density{};

using mass_flow_rate_t = decltype(kilogram<> / second<>);
inline constexpr mass_flow_rate_t mass_flow_rate{};

using radiance_t = decltype( watt / steradian * meter<-2> );
inline constexpr radiance_t radiance{};

using spectral_radiance_t = decltype( watt / steradian * meter<-3> );
inline constexpr spectral_radiance_t spectral_radiance{};

using spectral_power_t = decltype(watt / meter<>);
inline constexpr spectral_power_t spectral_power{};

using absorbed_dose_rate_t = decltype(gray / second<>);
inline constexpr absorbed_dose_rate_t absorbed_dose_rate{};

using fuel_efficiency_t = decltype(meter<-2>);
inline constexpr fuel_efficiency_t fuel_efficiency{};

using spectral_irradiance_t = decltype(watt / meter<3>);
inline constexpr spectral_irradiance_t spectral_irradiance{};

using power_density_t = decltype(watt / meter<3>);
inline constexpr power_density_t power_density{};

using energy_flux_density_t = decltype( joule * meter<-2> * second<-1> );
inline constexpr energy_flux_density_t energy_flux_density{};
// duplicates with surface tension [N/m, kg/s^2] 
// template <> struct abbreviation<energy_flux_density_t> { static constexpr char str[] = "J/(m^2·s)"; };

using compressibility_t = reciprocal_t<pressure_t>;
inline constexpr compressibility_t compressibility{};

using radiant_exposure_t = decltype(joule / meter<2>);
inline constexpr radiant_exposure_t radiant_exposure{};
// template <> struct abbreviation<radiant_exposure_t> { static constexpr char str[] = "J/m^2"; };

using moment_of_inertia_t = decltype(kilogram<> * meter<2>);
inline constexpr moment_of_inertia_t moment_of_inertia{};

using specific_angular_momentum_t = decltype(meter<2> * second<-1>);
inline constexpr specific_angular_momentum_t specific_angular_momentum{};

using radiant_intensity_t = decltype(watt / steradian);
inline constexpr radiant_intensity_t radiant_intensity{};

using spectral_intensity_t = decltype( watt / steradian * meter<-1> );
inline constexpr spectral_intensity_t spectral_intensity{};


using dynamic_viscosity_t = decltype(pascal * seconds);
inline constexpr dynamic_viscosity_t dynamic_viscosity{};

using angular_velocity_t = decltype(radian / seconds);
inline constexpr angular_velocity_t angular_velocity{};

using angular_accelaration_t = decltype(radian / second<2>);
inline constexpr angular_accelaration_t angular_accelaration{};
}

namespace mitama {
template <> struct abbreviation<si::angular_accelaration_t> { static constexpr char str[] = "rad/s^2"; };
template <> struct abbreviation<si::angular_velocity_t> { static constexpr char str[] = "rad/s"; };
template <> struct abbreviation<si::dynamic_viscosity_t> { static constexpr char str[] = "Pa·s"; };
template <> struct abbreviation<si::spectral_intensity_t> { static constexpr char str[] = "W/(sr·m)"; };
template <> struct abbreviation<si::radiant_intensity_t> { static constexpr char str[] = "W/sr"; };
template <> struct abbreviation<si::specific_angular_momentum_t> { static constexpr char str[] = "m^2/s"; };
template <> struct abbreviation<si::compressibility_t> { static constexpr char str[] = "Pa^-1"; };
template <> struct abbreviation<si::absorbed_dose_rate_t> { static constexpr char str[] = "Gy/s"; };
template <> struct abbreviation<si::spectral_radiance_t> { static constexpr char str[] = "W/(sr·m^3)"; };
template <> struct abbreviation<si::radiance_t> { static constexpr char str[] = "W/(sr·m^2)"; };
template <> struct abbreviation<si::irradiance_t> { static constexpr char str[] = "W/m"; };
template <> struct abbreviation<si::stiffness_t> { static constexpr char str[] = "N/m"; };
template <> struct abbreviation<si::power_density_t> { static constexpr char str[] = "W/m^3"; };
}

// Molar SI derived units
namespace mitama::si {
using molarity_t = decltype(mol<> / meter<3>);
inline constexpr molarity_t molarity{};

using molar_volume_t = decltype(meter<3> / mol<>);
inline constexpr molar_volume_t molar_volume{};

using molar_heat_capacity_t = decltype( joule / (kelvin<> * mol<>) );
inline constexpr molar_heat_capacity_t molar_heat_capacity{};

using molar_entropy_t = decltype( joule / (kelvin<> * mol<>) );
inline constexpr molar_entropy_t molar_entropy{};

using molar_energy_t = decltype(joule / mol<>);
inline constexpr molar_energy_t molar_energy{};

using molar_conductivity_t = decltype(siemens * meter<2> / mol<>);
inline constexpr molar_conductivity_t molar_conductivity{};

using molality_t = decltype(mol<> / kilogram<>);
inline constexpr molality_t molality{};

using molar_mass_t = decltype(kilogram<> / mol<>);
inline constexpr molar_mass_t molar_mass{};

using catalytic_efficiency_t = decltype(meter<3> / (mol<> * second<>));
inline constexpr catalytic_efficiency_t catalytic_efficiency{};
}

namespace mitama {
template <> struct abbreviation<si::catalytic_efficiency_t> { static constexpr char str[] = "m^3/(mol·s)"; };
template <> struct abbreviation<si::molar_mass_t> { static constexpr char str[] = "kg/mol"; };
template <> struct abbreviation<si::molality_t> { static constexpr char str[] = "mol/kg"; };
template <> struct abbreviation<si::molar_conductivity_t> { static constexpr char str[] = "S·m^2/mol"; };
template <> struct abbreviation<si::molar_energy_t> { static constexpr char str[] = "J/mol"; };
template <> struct abbreviation<si::molar_entropy_t> { static constexpr char str[] = "J/(K·mol)"; };
template <> struct abbreviation<si::molar_volume_t> { static constexpr char str[] = "m^3/mol"; };
template <> struct abbreviation<si::molarity_t> { static constexpr char str[] = "mol/m^3"; };
}

// Electromagnetic SI derived units
namespace mitama::si {
using electric_displacement_field_t = decltype(coulomb / meter<2>);
inline constexpr electric_displacement_field_t electric_displacement_field{};

using polarization_density_t = decltype(coulomb / meter<2>);
inline constexpr polarization_density_t polarization_density{};

using electric_charge_density_t = decltype(coulomb / meter<3>);
inline constexpr electric_charge_density_t electric_charge_density{};

using charge_density_t = decltype(coulomb / meter<3>);
inline constexpr electric_charge_density_t charge_density{};

using electric_current_density_t = decltype(ampere<> / meter<2>);
inline constexpr electric_current_density_t electric_current_density{};

using electrical_conductivity_t = decltype(siemens / meter<>);
inline constexpr electrical_conductivity_t electrical_conductivity{};

using permittivity_t = decltype(farad / meter<>);
inline constexpr permittivity_t permittivity{};

using permeability_t = decltype(henry / meter<>);
inline constexpr permeability_t permeability{};

using electric_field_strength_t = decltype(volt<1> / meters);
inline constexpr electric_field_strength_t electric_field_strength{};

using magnetization_t = decltype(ampere<> / meter<>);
inline constexpr magnetization_t magnetization{};

using magnetic_field_strength_t = decltype(ampere<> / meter<>);
inline constexpr magnetic_field_strength_t magnetic_field_strength{};

using exposure_t = decltype(coulomb / kilogram<>);
inline constexpr exposure_t exposure{};

using resistivity_t = decltype(ohm * meter<>);
inline constexpr resistivity_t resistivity{};

using linear_charge_density_t = decltype(coulomb / meter<>);
inline constexpr linear_charge_density_t linear_charge_density{};

using magnetic_dipole_moment_t = decltype(joule / tesla);
inline constexpr magnetic_dipole_moment_t magnetic_dipole_moment{};
// template <> struct abbreviation<magnetic_dipole_moment_t> { static constexpr char str[] = "J/T"; };

using electron_mobility_t = decltype( meter<2> * volt<-1> * second<-1> );
inline constexpr electron_mobility_t electron_mobility{};

using magnetic_reluctance_t = reciprocal_t<inductance_t>;
inline constexpr magnetic_reluctance_t magnetic_reluctance{};

using magnetic_vector_potential_t = decltype(weber / meter<>);
inline constexpr magnetic_vector_potential_t magnetic_vector_potential{};

using magnetic_moment_t = decltype(weber * meter<>);
inline constexpr magnetic_moment_t magnetic_moment{};

using magnetic_rigidity_t = decltype(tesla * meter<>);
inline constexpr magnetic_rigidity_t magnetic_rigidity{};

using magnetomotive_force_t = decltype(ampere<> * radian);
inline constexpr magnetomotive_force_t magnetomotive_force{};

using magnetic_susceptibility_t = decltype(meter<> / henry);
inline constexpr magnetic_susceptibility_t magnetic_susceptibility{};
}

namespace mitama {
template <> struct abbreviation<si::magnetic_susceptibility_t> { static constexpr char str[] = "m/H"; };
template <> struct abbreviation<si::magnetic_rigidity_t> { static constexpr char str[] = "T·m"; };
template <> struct abbreviation<si::magnetic_moment_t> { static constexpr char str[] = "Wb·m"; };
template <> struct abbreviation<si::magnetic_vector_potential_t> { static constexpr char str[] = "Wb/m"; };
template <> struct abbreviation<si::magnetic_reluctance_t> { static constexpr char str[] = "H^-1"; };
template <> struct abbreviation<si::electron_mobility_t> { static constexpr char str[] = "m^2/(V·s)"; };
template <> struct abbreviation<si::resistivity_t> { static constexpr char str[] = "Ω·m"; };
template <> struct abbreviation<si::linear_charge_density_t> { static constexpr char str[] = "C/m"; };
template <> struct abbreviation<si::exposure_t> { static constexpr char str[] = "C/kg"; };
template <> struct abbreviation<si::magnetic_field_strength_t> { static constexpr char str[] = "A/m"; };
template <> struct abbreviation<si::electric_field_strength_t> { static constexpr char str[] = "V/m"; };
template <> struct abbreviation<si::permeability_t> { static constexpr char str[] = "H/m"; };
template <> struct abbreviation<si::permittivity_t> { static constexpr char str[] = "F/m"; };
template <> struct abbreviation<si::electrical_conductivity_t> { static constexpr char str[] = "S/m"; };
template <> struct abbreviation<si::electric_current_density_t> { static constexpr char str[] = "A/m^2"; };
template <> struct abbreviation<si::electric_charge_density_t> { static constexpr char str[] = "C/m^3"; };
template <> struct abbreviation<si::electric_displacement_field_t> { static constexpr char str[] = "C/m^2"; };
}

// Photometric SI derived units
namespace mitama::si {
using luminous_energy_t = decltype(lumen * second<>);
inline constexpr luminous_energy_t luminous_energy{};

using luminous_exposure_t = decltype(lux * second<>);
inline constexpr luminous_exposure_t luminous_exposure{};

using luminance_t = decltype(candela<> * meter<-2>);
inline constexpr luminance_t luminance{};

using luminous_efficacy_t = decltype(lumen / watt);
inline constexpr luminous_efficacy_t luminous_efficacy{};
}

namespace mitama {
template <> struct abbreviation<si::luminous_efficacy_t> { static constexpr char str[] = "lm/W"; };
template <> struct abbreviation<si::luminance_t> { static constexpr char str[] = "lx·s"; };
template <> struct abbreviation<si::luminous_exposure_t> { static constexpr char str[] = "lx·s"; };
template <> struct abbreviation<si::luminous_energy_t> { static constexpr char str[] = "lm·s"; };
}

// Thermodynamic SI derived units
namespace mitama::si {
using heat_capacity_t = decltype(joule / kelvins);
inline constexpr heat_capacity_t heat_capacity{};
using entropy_t = decltype(joule / kelvins);
inline constexpr entropy_t entropy{};

using specific_heat_capacity_t = decltype( joule * kilogram<-1> * kelvin<-1> );
inline constexpr specific_heat_capacity_t specific_heat_capacity{};
using specific_entropy_t = decltype( joule / (kilograms * kelvins) );
inline constexpr specific_entropy_t specific_entropy{};

using thermal_conductivity_t = decltype( watt * meter<-1> * kelvin<-1> );
inline constexpr thermal_conductivity_t thermal_conductivity{};

using heat_flux_t = decltype(watt * meter<-2>);
inline constexpr heat_flux_t heat_flux{};

using thermal_resistance_t = decltype(kelvin<> / watt);
inline constexpr thermal_resistance_t thermal_resistance{};

using thermal_expansion_coefficient_t = reciprocal_t<kelvin_t>;
inline constexpr thermal_expansion_coefficient_t thermal_expansion_coefficient{};

using temperature_gradient_t = decltype(kelvin<> / meter<>);
inline constexpr temperature_gradient_t temperature_gradient{};
}

namespace mitama {
template <> struct abbreviation<si::thermal_resistance_t> { static constexpr char str[] = "K/W"; };
template <> struct abbreviation<si::heat_flux_t> { static constexpr char str[] = "W/m^2"; };
template <> struct abbreviation<si::thermal_conductivity_t> { static constexpr char str[] = "W/(m·K)"; };
template <> struct abbreviation<si::specific_heat_capacity_t> { static constexpr char str[] = "J/(kg·K)"; };
template <> struct abbreviation<si::entropy_t> { static constexpr char str[] = "J/K"; };
}