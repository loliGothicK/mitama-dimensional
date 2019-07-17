#ifndef MITAMA_DIMENSIONAL_SYSTEMS_SI_QUANTITY_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_SI_QUANTITY_HPP
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/system.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/systems/si/derived_units/angle.hpp>
#include <mitama/dimensional/systems/si/derived_units/solid_angle.hpp>

namespace mitama::systems::si {
  template < class D, typename T > 
  using quantity_t
    = ::mitama::quantity_t<D, T,
        ::mitama::system<
          ampere_t,
          luminous_intensity,
          thermodynamic_temperature,
          mass,
          length,
          amount_of_substance,
          time,
          angle,
          solid_angle
    >>;
}

#endif // !MITAMA_DIMENSIONAL_SYSTEMS_SI_QUANTITY_HPP
