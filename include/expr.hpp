#ifndef MITAMA_DIMENSIONAL_EXPR_HPP
#define MITAMA_DIMENSIONAL_EXPR_HPP
#include <type_traits>
#include <utility>
#include "quantity.hpp"
#include "derived_units/dgree_celsius.hpp"
#include "mitamagic/utility.hpp"

namespace mitama
{
template <class Quantity>
class delta
{
  Quantity value_;

public:
  using value_type = typename Quantity::value_type;

  constexpr explicit delta(Quantity const &value) : value_(value) {}

  template <class Target, std::enable_if_t<std::is_convertible_v<Target, Quantity>, bool> = false>
  constexpr operator Target() { return {value_}; }

  constexpr value_type count() const { value_.get(); }
  constexpr value_type get() const { value_; }
};

template <class Q1, class Q2>
inline constexpr auto operator+(Q1 const &q1, delta<Q2> const &d2) -> decltype(std::declval<Q1>() + std::declval<Q2>())
{
  return q1 + d2.get();
}

template <class Q1, class Q2>
inline constexpr auto operator-(Q1 const &q1, delta<Q2> const &d2) -> decltype(std::declval<Q1>() - std::declval<Q2>())
{
  return q1 - d2.get();
}

template <class Q1, class Q2>
inline constexpr auto operator*(Q1 const &q1, delta<Q2> const &d2) -> decltype(std::declval<Q1>() * std::declval<Q2>())
{
  return q1 * d2.get();
}

template <class Q1, class Q2>
inline constexpr auto operator/(Q1 const &q1, delta<Q2> const &d2) -> decltype(std::declval<Q1>() / std::declval<Q2>())
{
  return q1 / d2.get();
}

template <class Q1, class Q2>
inline constexpr auto operator+(delta<Q1> const &d1, Q2 const &q2) -> decltype(std::declval<Q1>() + std::declval<Q2>())
{
  return d1.get() + q2;
}

template <class Q1, class Q2>
inline constexpr auto operator-(delta<Q1> const &d1, Q2 const &q2) -> decltype(std::declval<Q1>() - std::declval<Q2>())
{
  return d1.get() + q2;
}

template <class Q1, class Q2>
inline constexpr auto operator*(delta<Q1> const &d1, Q2 const &q2) -> decltype(std::declval<Q1>() * std::declval<Q2>())
{
  return d1.get() + q2;
}

template <class Q1, class Q2>
inline constexpr auto operator/(delta<Q1> const &d1, Q2 const &q2) -> decltype(std::declval<Q1>() / std::declval<Q2>())
{
  return d1.get() + q2;
}

template <class Q1, class Q2>
inline constexpr auto operator+(delta<Q1> const &d1, delta<Q2> const &q2) -> decltype(std::declval<Q1>() + std::declval<Q2>())
{
  return d1.get() + q2.get();
}

template <class Q1, class Q2>
inline constexpr auto operator-(delta<Q1> const &d1, delta<Q2> const &q2) -> decltype(std::declval<Q1>() - std::declval<Q2>())
{
  return d1.get() + q2.get();
}

template <class Q1, class Q2>
inline constexpr auto operator*(delta<Q1> const &d1, delta<Q2> const &q2) -> decltype(std::declval<Q1>() * std::declval<Q2>())
{
  return d1.get() + q2.get();
}

template <class Q1, class Q2>
inline constexpr auto operator/(delta<Q1> const &d1, delta<Q2> const &q2) -> decltype(std::declval<Q1>() / std::declval<Q2>())
{
  return d1.get() + q2.get();
}

struct expr_tag{};

template <class T>
inline constexpr bool is_expr_v = std::is_base_of_v<expr_tag, T>;


template < class T > struct lexical_converter;

template < class T, class Head, class... Tail >
struct lexical_converter<quantity_t<dimensional_t<Head, Tail...>, T>>
{
  template < class Quantity >
  static constexpr auto convert(Quantity&& value) {
    if constexpr (is_complete_type_v<converter<std::decay_t<Quantity>, quantity_t<dimensional_t<Head>, T>>>)
    {
      return quantity_t<dimensional_t<Head>, T>{
          converter<std::decay_t<Quantity>, quantity_t<dimensional_t<Head>, T>>::convert(value)};
    }
    else
    {
      return lexical_converter<quantity_t<dimensional_t<Tail...>, T>>::convert(value);
    }
  }
};

template < class T, class Head >
struct lexical_converter<quantity_t<dimensional_t<Head>, T>>
{
  template < class Quantity >
  static constexpr auto convert(Quantity&& value) {
    if constexpr (is_complete_type_v<converter<std::decay_t<Quantity>, quantity_t<dimensional_t<Head>, T>>>)
    {
      return quantity_t<dimensional_t<Head>, T>{
          converter<std::decay_t<Quantity>, quantity_t<dimensional_t<Head>, T>>::convert(value)};
    }
    else
    {
      return value;
    }
  }
};


template <class Quantity>
struct quantity_wrapper : private expr_tag
{
  Quantity value_;
  constexpr quantity_wrapper(Quantity value) : value_(value) {}
  constexpr Quantity eval() const { return value_; }
  template < class To >
  constexpr auto lexical_evaluate() const { return lexical_converter<To>::template convert(value_); }
};

template < class T > quantity_wrapper(T&&) -> quantity_wrapper<std::decay_t<T>>;

template < class T >
inline constexpr auto as_expr(T&& t) {
  if constexpr (is_expr_v<std::decay_t<T>>) {
    return std::forward<T>(t);
  }
  else {
    return quantity_wrapper{std::forward<T>(t)};
  }
}

template < class T >
using as_expr_t = std::decay_t<decltype(as_expr(std::declval<T>()))>;


template <class BinaryOperator, class L, class R>
class LexicalExpression : private expr_tag
{
  L lhs_;
  R rhs_;
public:
  constexpr LexicalExpression(L const& lhs, R const& rhs): lhs_(lhs), rhs_(rhs) {}

  template < class To >
  auto lexical_evaluate() const {
    return BinaryOperator::apply(lhs_.template lexical_evaluate<To>(), rhs_.template lexical_evaluate<To>());
  }

  constexpr auto eval() const
  {
    return BinaryOperator::apply(lhs_.eval(), rhs_.eval());
  }

  template <class Target,
      std::enable_if_t<std::conjunction_v<
        is_quantity<Target>
      >, bool> = false>
  constexpr operator Target() const { return {this->lexical_evaluate<Target>()}; }

};

template <class Quantity, class Expr>
inline constexpr std::enable_if_t<is_expr_v<Expr>, Quantity&>
operator|=(Quantity& quantity, Expr const& expr) {
  quantity = expr.eval();
  return quantity;
}

} // namespace mitama

namespace mitama::operators
{
struct Add_
{
  template <typename L, typename R>
  static constexpr auto apply(L const &lhs, R const &rhs)
  {
    return lhs + rhs;
  }
};

struct Sub_
{
  template <typename L, typename R>
  static constexpr auto apply(L const &lhs, R const &rhs)
  {
    return delta{lhs - rhs};
  }
};

struct Mul_
{
  template <typename L, typename R>
  static constexpr auto apply(L const &lhs, R const &rhs)
  {
    return lhs * rhs;
  }
};

struct Div_
{
  template <typename L, typename R>
  static constexpr auto apply(L const &lhs, R const &rhs)
  {
    return lhs / rhs;
  }
};

} // namespace mitama::operators

namespace mitama
{
template <class L, class R, std::enable_if_t<is_expr_v<std::decay_t<L>> || is_expr_v<std::decay_t<R>>, bool> = false>
inline constexpr LexicalExpression<operators::Add_, as_expr_t<L>, as_expr_t<R>>
operator+(L const & lhs, R const & rhs)
{
  return {as_expr(lhs), as_expr(rhs)};
}
template <class L, class R, std::enable_if_t<is_expr_v<std::decay_t<L>> || is_expr_v<std::decay_t<R>>, bool> = false>
inline constexpr LexicalExpression<operators::Sub_, as_expr_t<L>, as_expr_t<R>>
operator-(L const & lhs, R const & rhs)
{
  return {as_expr(lhs), as_expr(rhs)};
}
template <class L, class R, std::enable_if_t<is_expr_v<std::decay_t<L>> || is_expr_v<std::decay_t<R>>, bool> = false>
inline constexpr LexicalExpression<operators::Mul_, as_expr_t<L>, as_expr_t<R>>
operator*(L const & lhs, R const & rhs)
{
  return {as_expr(lhs), as_expr(rhs)};
}
template <class L, class R, std::enable_if_t<is_expr_v<std::decay_t<L>> || is_expr_v<std::decay_t<R>>, bool> = false>
inline constexpr LexicalExpression<operators::Div_, as_expr_t<L>, as_expr_t<R>>
operator/(L const & lhs, R const & rhs)
{
  return {as_expr(lhs), as_expr(rhs)};
}
} // namespace mitama

#endif