#ifndef MITAMA_DIMENSIONAL_EXPR_HPP
#define MITAMA_DIMENSIONAL_EXPR_HPP
#include "fwd/expr_fwd.hpp"
#include "quantity.hpp"
#include "arithmetic.hpp"
#include "nonsi_units/degree_celsius.hpp"
#include "mitamagic/utility_ext.hpp"
#include <type_traits>
#include <utility>

namespace mitama
{

struct expr_tag{};

template <class T>
inline constexpr bool is_expr_v = std::is_base_of_v<expr_tag, T>;


template < class T > struct lexical_converter;

template <template <class> class Synonym, class T, class Head, class... Tail >
struct lexical_converter<quantity_t<Synonym<dimensional_t<Head, Tail...>>, T>>
{
  template < class Quantity >
  static constexpr auto convert(Quantity&& value) {
    if constexpr (is_complete_type_v<converter<std::decay_t<Quantity>, quantity_t<Synonym<dimensional_t<Head>>, T>>>)
    {
      return quantity_t<Synonym<dimensional_t<Head>>, T>{
          converter<std::decay_t<Quantity>, quantity_t<Synonym<dimensional_t<Head>>, T>>::convert(value)};
    }
    else
    {
      return lexical_converter<quantity_t<Synonym<dimensional_t<Tail...>>, T>>::convert(value);
    }
  }
};

template < template <class> class Synonym, class T, class Head >
struct lexical_converter<quantity_t<Synonym<dimensional_t<Head>>, T>>
{
  template < class Quantity >
  static constexpr auto convert(Quantity&& value) {
    if constexpr (is_complete_type_v<converter<std::decay_t<Quantity>, quantity_t<Synonym<dimensional_t<Head>>, T>>>)
    {
      return quantity_t<Synonym<dimensional_t<Head>>, T>{
          converter<std::decay_t<Quantity>, quantity_t<Synonym<dimensional_t<Head>>, T>>::convert(value)};
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
    return lhs - rhs;
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