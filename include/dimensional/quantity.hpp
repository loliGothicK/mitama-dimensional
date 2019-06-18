#ifndef MITAMA_DIMENSIONAL_QUANTITY_HPP
#define MITAMA_DIMENSIONAL_QUANTITY_HPP
#include <dimensional/fwd/quantity_fwd.hpp>
#include <dimensional/dimensional_traits.hpp>

namespace mitama {

template < class >
struct dimensionless_converter {};

template < template <class> class Synonym, class T, class... B >
struct dimensionless_converter<quantity_t<Synonym<dimensional_t<>>, T, system<B...>>> {
  operator T() const { return static_cast<quantity_t<Synonym<dimensional_t<>>, T> const*>(this)->value(); }
};


// Into Trait
template < class Quantity >
class Into;

template < template <class> class Synonym, class T, class... Units, class... B >
class Into<quantity_t<Synonym<dimensional_t<Units...>>, T, system<B...>>> {
  quantity_t<Synonym<dimensional_t<Units...>>, T, system<B...>> const& quantity_;
public:
  constexpr explicit Into(quantity_t<Synonym<dimensional_t<Units...>>, T, system<B...>> const& q): quantity_(q) {}
  // explicitly deleted
  Into() = delete;
  Into(Into const&) = delete;
  Into(Into&&) = delete;
  Into& operator=(Into const&) = delete;
  Into& operator=(Into&&) = delete;

  template < class To,
            std::enable_if_t<is_same_dimensional_v<
              remove_dim_if_t<has_dimensionless_tag, To>,
              remove_dim_if_t<has_dimensionless_tag, quantity_t<Synonym<dimensional_t<Units...>>, T, system<B...>>>>
    , bool> = false >
  constexpr operator To() const {
    return To(quantity_.value());
  }
};


template < class To, class From >
inline constexpr std::enable_if_t<is_dimensional_convertible_v<From, To>, To>
dimensional_convert(From const& from) {
  if constexpr (is_complete_type_v<converter<From, To>>){
    return To{::mitama::converter<From, To>::convert(from)};
  }
  else {
    return To{::mitama::mitamagic::converted_value<To>(from)};
  }
}

} // namespace mitama

namespace mitama {

template <class T, template <class> class Synonym, class...Units, class... B>
class quantity_t<Synonym<dimensional_t<Units...>>, T, system<B...>>
  : public dimensionless_converter<quantity_t<Synonym<dimensional_t<Units...>>, T>>
{
  T value_;
public:
  using value_type = T;
  using dimension_type = dimensional_t<Units...>;
  using system_type = system<B...>;

  constexpr quantity_t(): value_{} {}

  template < class Dimension, auto Value,
      std::enable_if_t<
        std::conjunction_v<
          std::is_convertible<std::decay_t<decltype(Value)>, T>,
          is_same_dimensional<dimension_type, Dimension>>
    , bool> = false>
  constexpr quantity_t(static_quantity_t<Dimension, Value>) noexcept
    : value_(Value)
  {}

  template < template <auto> class Pred,
             class Dimension,
             class U,
      std::enable_if_t<
        std::conjunction_v<
          std::is_convertible<U, T>>
    , bool> = false>
  constexpr quantity_t(refined<Pred, quantity_t<Dimension, U>> refined_) noexcept
    : quantity_t(refined_.get())
  {}

  template <class U = T,
      std::enable_if_t<
        std::conjunction_v<
          std::is_constructible<T, U>,
          std::is_convertible<U, T>>
    , bool> = false>
  constexpr quantity_t(U &&u) : value_(std::forward<U>(u)) {}

  template <class U = T,
      std::enable_if_t<
        std::conjunction_v<
          std::is_constructible<T, U>,
          std::negation<std::is_convertible<U, T>>>
    , bool> = false>
  explicit constexpr quantity_t(U &&u) : value_{std::forward<U>(u)} {}

  template <class... Args,
      std::enable_if_t<
          std::is_constructible_v<T, Args&&...>
    , bool> = false>
  explicit constexpr quantity_t(std::in_place_t, Args&& ...args)
    : value_(std::forward<Args>(args)...) {}

  template <class U, class... Args,
      std::enable_if_t<
          std::is_constructible_v<T, std::initializer_list<U>, Args&&...>
    , bool> = false>
  constexpr explicit quantity_t(std::in_place_t, std::initializer_list<U> il, Args&&... args)
    : value_(il, std::forward<Args>(args)...) {}

  template <
      class D, class U, class S,
      std::enable_if_t<is_same_dimensional_v<quantity_t, quantity_t<D, U, S>> &&
                           std::is_constructible_v<T, U> &&
                           std::is_convertible_v<U, T>,
                       bool> = false>
  constexpr quantity_t(quantity_t<D, U, S> const &o)
      : value_(mitamagic::converted_value<quantity_t>(o)) {}

  template <
      class D, class U, class S,
      std::enable_if_t<is_same_dimensional_v<quantity_t, quantity_t<D, U, S>> &&
                           std::is_constructible_v<T, U> &&
                           !std::is_convertible_v<U, T>,
                       bool> = false>
  explicit constexpr quantity_t(quantity_t<D, U, S> const &o)
      : value_{mitamagic::converted_value<quantity_t>(o)} {}

  template <
      class D, class U, class S,
      std::enable_if_t<is_complete_type_v<::mitama::converter<quantity_t<D, U, S>, quantity_t>> &&
                           std::is_constructible_v<T, U> &&
                           std::is_convertible_v<U, T>,
                       bool> = false>
  constexpr quantity_t(quantity_t<D, U, S> const &o)
      : value_(::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o)) {}

  template <
      class D, class U, class S,
      std::enable_if_t<is_complete_type_v<::mitama::converter<quantity_t<D, U, S>, quantity_t>> &&
                           std::is_constructible_v<T, U> &&
                           !std::is_convertible_v<U, T>,
                       bool> = false>
  explicit constexpr quantity_t(quantity_t<D, U, S> const &o)
      : value_{::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o)} {}

  template <
      class D, class U, class S,
      std::enable_if_t<is_same_dimensional_v<quantity_t, quantity_t<D, U, S>> &&
                           std::is_convertible_v<U, T>,
                       bool> = false>
  constexpr quantity_t &operator=(quantity_t<D, U, S> const &o) & {
    this->value_ = mitamagic::converted_value<quantity_t>(o);
    return *this;
  }

  template <
      class D, class U, class S,
      std::enable_if_t<is_complete_type_v<::mitama::converter<quantity_t<D, U, S>, quantity_t>> &&
                           std::is_convertible_v<U, T>,
                       bool> = false>
  constexpr quantity_t &operator=(quantity_t<D, U, S> const &o) & {
    this->value_ = ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
    return *this;
  }

  constexpr T value() const { return value_; }

  template < class F >
  constexpr auto validate(F&& validator) const & {
    return std::forward<F>(validator)(*this);
  }
  template < class F >
  constexpr auto validate(F&& validator) && {
    return std::forward<F>(validator)(std::move(*this));
  }

  template <
      class D, class U,
      std::enable_if_t<
        std::conjunction_v<
          is_complete_type<::mitama::converter<quantity_t<D, U>, quantity_t>>,
          is_equal_comparable_with<T, U>>
        , bool> = false>
  constexpr bool operator==(quantity_t<D, U> const &o) const {
    return this->value_ == ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
  }

  template <
      class D, class U,
      std::enable_if_t<
        std::conjunction_v<
          is_same_dimensional<quantity_t, quantity_t<D, U>>,
          is_equal_comparable_with<T, U>>
        , bool> = false>
  constexpr bool operator==(quantity_t<D, U> const &o) const {
    auto [l, r] = mitamagic::scaler<dimension_type, typename quantity_t<D, U>::dimension_type>::template value<std::common_type_t<T, U>>();
    return l * this->value() == r * o.value();
  }

  template <
      class D, class U,
      std::enable_if_t<
        std::conjunction_v<
          is_complete_type<::mitama::converter<quantity_t<D, U>, quantity_t>>,
          is_notequal_comparable_with<T, U>>
        , bool> = false>
  constexpr bool operator!=(quantity_t<D, U> const &o) const {
    return this->value_ != ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
  }

  template <
      class D, class U,
      std::enable_if_t<
        std::conjunction_v<
          is_same_dimensional<quantity_t, quantity_t<D, U>>,
          is_notequal_comparable_with<T, U>>
        , bool> = false>
  constexpr bool operator!=(quantity_t<D, U> const &o) const {
    auto [l, r] = mitamagic::scaler<dimension_type, typename quantity_t<D, U>::dimension_type>::template value<std::common_type_t<T, U>>();
    return l * this->value() != r * o.value();
  }

  template <
      class D, class U,
      std::enable_if_t<
        std::conjunction_v<
          is_complete_type<::mitama::converter<quantity_t<D, U>, quantity_t>>,
          is_less_comparable_with<T, U>>
        , bool> = false>
  constexpr bool operator<(quantity_t<D, U> const &o) const {
    return this->value_ < ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
  }

  template <
      class D, class U,
      std::enable_if_t<
        std::conjunction_v<
          is_same_dimensional<quantity_t, quantity_t<D, U>>,
          is_less_comparable_with<T, U>>
        , bool> = false>
  constexpr bool operator<(quantity_t<D, U> const &o) const {
    auto [l, r] = mitamagic::scaler<dimension_type, typename quantity_t<D, U>::dimension_type>::template value<std::common_type_t<T, U>>();
    return l * this->value() < r * o.value();
  }

  template <
      class D, class U,
      std::enable_if_t<
        std::conjunction_v<
          is_complete_type<::mitama::converter<quantity_t<D, U>, quantity_t>>,
          is_less_or_equal_comparable_with<T, U>>
        , bool> = false>
  constexpr bool operator<=(quantity_t<D, U> const &o) const {
    return this->value_ <= ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
  }

  template <
      class D, class U,
      std::enable_if_t<
        std::conjunction_v<
          is_same_dimensional<quantity_t, quantity_t<D, U>>,
          is_less_or_equal_comparable_with<T, U>>
        , bool> = false>
  constexpr bool operator<=(quantity_t<D, U> const &o) const {
    auto [l, r] = mitamagic::scaler<dimension_type, typename quantity_t<D, U>::dimension_type>::template value<std::common_type_t<T, U>>();
    return l * this->value() <= r * o.value();
  }

  template <
      class D, class U,
      std::enable_if_t<
        std::conjunction_v<
          is_complete_type<::mitama::converter<quantity_t<D, U>, quantity_t>>,
          is_greater_comparable_with<T, U>>
        , bool> = false>
  constexpr bool operator>(quantity_t<D, U> const &o) const {
    return this->value_ > ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
  }

  template <
      class D, class U,
      std::enable_if_t<
        std::conjunction_v<
          is_same_dimensional<quantity_t, quantity_t<D, U>>,
          is_greater_comparable_with<T, U>>
        , bool> = false>
  constexpr bool operator>(quantity_t<D, U> const &o) const {
    auto [l, r] = mitamagic::scaler<dimension_type, typename quantity_t<D, U>::dimension_type>::template value<std::common_type_t<T, U>>();
    return l * this->value() > r * o.value();
  }

  template <
      class D, class U,
      std::enable_if_t<
        std::conjunction_v<
          is_complete_type<::mitama::converter<quantity_t<D, U>, quantity_t>>,
          is_greater_or_equal_comparable_with<T, U>>
        , bool> = false>
  constexpr bool operator>=(quantity_t<D, U> const &o) const {
    return this->value_ >= ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
  }

  template <
      class D, class U,
      std::enable_if_t<
        std::conjunction_v<
          is_same_dimensional<quantity_t, quantity_t<D, U>>,
          is_greater_or_equal_comparable_with<T, U>>
        , bool> = false>
  constexpr bool operator>=(quantity_t<D, U> const &o) const {
    auto [l, r] = mitamagic::scaler<dimension_type, typename quantity_t<D, U>::dimension_type>::template value<std::common_type_t<T, U>>();
    return l * this->value() >= r * o.value();
  }

  auto operator-() const {
    if constexpr (std::is_integral_v<T>) {
      return quantity_t<Synonym<dimensional_t<Units...>>, decltype(-std::declval<T>()), system<B...>>{ -value_ };
    }
    else {
      return quantity_t{ -value_ };
    }
  }
  auto operator+() const {
    if constexpr (std::is_integral_v<T>) {
      return quantity_t<Synonym<dimensional_t<Units...>>, decltype(+std::declval<T>()), system<B...>>{ +value_ };
    }
    else {
      return quantity_t{ +value_ };
    }
  }

  Into<quantity_t> into() const& {
    return Into<quantity_t>(*this);
  }
};

template < class Dim, auto Value >
quantity_t(static_quantity_t<Dim, Value>) -> quantity_t<Dim, decltype(Value)>;

template < template <auto> class Pred, class Dim, class T >
quantity_t(refined<Pred, quantity_t<Dim, T>>) -> quantity_t<Dim, T>;

namespace mitamagic {
template <class Dim> struct into_dimensional;

template <int I, class Dim> struct into_dimensional<units_t<I, Dim>> {
  using type = si_base_units<dimensional_t<units_t<I, Dim>>>;
};

template <class... Units> struct into_dimensional<dimensional_t<Units...>> {
  using type = si_base_units<dimensional_t<Units...>>;
};

template <template<class>class Synonym, class... Units> struct into_dimensional<Synonym<dimensional_t<Units...>>> {
  using type = Synonym<dimensional_t<Units...>>;
};

template <class Unit>
using into_dimensional_t = typename into_dimensional<Unit>::type;
} // namespace mitamagic

} // namespace mitama

namespace mitama {

template <class U1, class U2,
          std::enable_if_t<
            std::conjunction_v<is_dimensional_quantifier<U1>, is_dimensional_quantifier<U2>>
        , bool> = false>
constexpr mitamagic::quotient_t<mitamagic::into_dimensional_t<U1>,
                                mitamagic::into_dimensional_t<U2>>
operator*(U1, U2) {
  return {};
}

template <class U1, class U2,
          std::enable_if_t<std::conjunction_v<is_dimensional_quantifier<U1>, is_dimensional_quantifier<U2>>, bool> =
              false>
constexpr mitamagic::quotient_t<
    mitamagic::into_dimensional_t<U1>,
    mitamagic::inverse_t<mitamagic::into_dimensional_t<U2>>>
operator/(U1, U2) {
  return {};
}

template <class Dim, class T>
constexpr std::enable_if_t<is_dimensional_quantifier<Dim>::value, quantity_t<Dim, std::decay_t<T>>>
operator|(T &&t, Dim) {
  return { mitama::decay_copy(std::forward<T>(t)) };
}

using dimless_t = si_base_units<dimensional_t<>>;

template <class Dim, class T = double>
using quantity = quantity_t<mitamagic::into_dimensional_t<Dim>, T>;

template <class T, class Unit, class... Units>
using quantity_for = std::decay_t<decltype(std::declval<T>() | (std::declval<Unit>() * ... * std::declval<Units>()))>;

} // namespace mitama
#endif