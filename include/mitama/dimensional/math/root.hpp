#ifndef MITAMA_DIMENSIONAL_MATH_ROOT_HPP
#define MITAMA_DIMENSIONAL_MATH_ROOT_HPP

#include <cmath>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/systems/si/base_units/meter.hpp>
namespace mitama {

template < template <class> class Synonym, class T, class... Units, class S >
auto sqrt(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const& quantity) {
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<1, 2>>::type>, T, S>
        {
            static_cast<T>(std::sqrt(quantity.value()))
        };
}


template < template <class> class Synonym, class T, class... Units, class S >
auto cbrt(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const& quantity) {
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<1, 3>>::type>, T, S>
        {
            static_cast<T>(std::cbrt(quantity.value()))
        };
}

template < class... Quantities,
    std::enable_if_t<(sizeof...(Quantities) == 2 || sizeof...(Quantities) == 3)
                  && std::conjunction_v<::mitama::is_same_dimensional<Quantities, ::mitama::quantity_t<::mitama::systems::si::meter_t>>...>,
                bool> = false>
auto hypot(Quantities... quantities) {
    return ::mitama::common_quantity_t<std::decay_t<Quantities>...>{ std::hypot(static_cast<::mitama::common_quantity_t<std::decay_t<Quantities>...>>(quantities).value()...) };
}

}

#endif