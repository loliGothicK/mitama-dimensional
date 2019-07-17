#ifndef MITAMA_DIMENSIONAL_SYSTEM_HPP
#define MITAMA_DIMENSIONAL_SYSTEM_HPP
#include <mitama/dimensional/mitamagic/type_list.hpp>
#include <mitama/dimensional/fwd/quantity_fwd.hpp>

namespace mitama {
  template < class... Dim >
  struct system: private Dim... {};

  template < template <class> class Pred >
  struct system_if {
    template < class T >
    static constexpr bool value = Pred<T>::value;
  };

  template < class, class >
  struct common_system;

  template < class... Dim >
  struct common_system<system<>, system<Dim...>>
  {
    using type = system<Dim...>;
  };

  template < class... Dim >
  struct common_system<system<Dim...>, system<>>
  {
    using type = system<Dim...>;
  };

  template <>
  struct common_system<system<>, system<>>
  {
    using type = system<>;
  };

  template < class S1, class S2 >
  using common_system_t = typename common_system<S1, S2>::type;
}

#endif // !MITAMA_DIMENSIONAL_SYSTEM_HPP
