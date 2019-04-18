# Basic Concepts
-------------

## TL;DR

`mitama::quantity_t` is a class template that is represents a dimensional quantity.
quantity_t has units as a phantom type.
It can handle rational exponents like $m ^ {2/3}$ as a unit.

In the following are the explanations of the detailed definitions, their techniques, and metaprogramming, but if you are not interested, please proceed to the next page.

## Representation of Unit
----------------------------

Basic unit of a dimension $\lambda$ with exponent and scale is represented as a pair of exponent $e \in \mathbb{Q}$ and scale $s \in \mathbb{Q}$:

$$
U_\lambda := (e, s)_{\lambda}
$$

for example,

$$
m = (1, 1)_{length} \\
mm = (1, 1/1000)_{length} \\
mm^{2/3} = (2/3, 1/1000)_{length}
$$

This corresponds to `units_t` in Mitama.Dimensional.

## Representation of Derived Unit
----------------------------

Let $\Lambda$ is a set of basic dimensions of Derived Unit, derived units is represented as a sets of Unit over $\Lambda$:

$$
D_\Lambda := {\{U_\lambda\}}_{\lambda \in \Lambda}
$$

for example,

$$
N = kg \cdot m^2 \cdot s^{-2} = \{ (1, 1)_{mass}, (2, 1)_{length}, (-2, 1)_{time}  \}
$$

This corresponds to `dimensional_t` in Mitama.Dimensional.


## Type System of Quantity
----------------------------

Dimensional quantity is designed as `quantity_t`, which is a class that represents a dimensional quantity based on `ValueType` that is distinguished by a phantom type `dimensional_t<Units...>`:

```cpp
template < template <class> class Synonym, class ValueType, class... Units >
class quantity_t<Synonym<dimensional_t<Units...>>, ValueType>
```

`Synonym` is a phantom template template for aliasing.

And each type of `Units...` is designed as `units_t`:

```cpp
template < class BaseDimension, // base dimension tag class
           class Exponent,      // std::ratio
           class Scale          // std::ratio
>
class units_t<BaseDimension, Exponent, Scale>
```

## Tracking units and conversion factors in types
----------------------------

When value $a$ has derived unit $D_\Lambda$, let that be denoted as:

$$
a: D_\Lambda
$$

then

**$(a:A_\Lambda) \pm (b:B_\Lambda)$**

$$
= a \pm b:{\{ ( e, min(s_a, s_b) )_{\lambda} \ | \ (e_a, s_a)_{\lambda} \in A_\Lambda, (e_b, s_b)_{\lambda} \in B_\Lambda \}}_{\lambda \in \Lambda}
$$

$min (s_a, s_b)$ means it is automatically converted to a high precision factor.


```cpp
// `a` = 1 mm
quantity_t<millimetre_t> a = 1;
// `b`  = 1 m
quantity_t<metre_t> b = 1;

// a + b will be millimetre
a + b; // 1001 mm
```

**$(a:A_{\Gamma}) \times (b:B_{\Lambda})$**

$$
= a \times b: {\{ ( e_a + e_b, min(s_a, s_b) )_{\sigma} \ | \ (e_a, s_a)_{\sigma} \in A_\sigma, (e_b, s_b)_{\sigma} \in B_\sigma \}}_{\sigma \in \Gamma \cap \Lambda  } \\
\cup {\{ (e_a, s_a)_{\gamma} \ | \ (e_a, s_a)_{\gamma} \in A_\gamma\}}_{\gamma \in \Gamma \backslash \Lambda  } \\
\cup {\{ (e_b, s_b)_{\lambda} \ | \ (e_b, s_b)_{\lambda} \in B_\lambda\}}_{\lambda \in \Lambda \backslash \Gamma  }
$$

It is automatically converted to a high precision factor, too.


**$(a:A_{\Gamma}) \div (b:B_{\Lambda})$**

define

$$
{D_\Lambda}^{-1} := {\{ (-e, s)_{\lambda} \ | \ (e, s)_{\lambda} \in D_\Lambda \}}_{\lambda \in \Lambda}
$$

and 

$$
(a:A_{\Gamma}) \div (b:B_{\Lambda}) := (a:A_{\Gamma}) \times (b^{-1}:{B_{\Lambda}}^{-1})
$$


## Implementation of dimension inducing

Example:

$$
[m^2 \cdot s^{-1}] \times [kg \cdot s^{-1}] \leadsto [m^2 \cdot s^{-2} \cdot kg]
$$

First, let 

$$
mul(U_1, U_2) := (e_1 + e_2, min(s_1, s_2))_\lambda
$$

And consider simple dual loop:


1. Pick a `unit_t` **A** from left.
2. If there is a right for **B** with the same dimensions as **A**, push If there is a right for **B** with the same dimensions as **A**, push $$mul(A, B)$$ result and pop **A** and remove **B** from right, else push **A** to result and pop **A**.
3. If left does not empty, return to 1, else push the rest of right to result

start with empty result.

$$
left = [m^2 \cdot s^{-1}] \\
right = [kg \cdot s^{-1}] \\
result = [\ ]
$$

pick $A=m^2$, and not found B.
$$
left = [s^{-1}] \\
right = [kg \cdot s^{-1}] \\
result = [m^2]
$$

pick $A=s^{-1}$, found $B=s^{-1}$.

left = [\ ] \\
right = [kg] \\
result = [m^2 \cdot s^{-2}]
$$

push the rest of right to result

$$
left = [\ ] \\
right = [\ ] \\
result = [m^2 \cdot s^{-2} \cdot kg]
$$

-- end example

## Dive into type-level programing

**1st step: Implementing in runtime**

When you do type-level programming, do you suddenly declare classes?
It's a good idea to start by identifying what you need for type-level programming through runtime programming.
Well, I usually declare classes suddenly.

Here is the runtime code that derives the result of the unit multiplication described in the example above:

[Wandbox](https://wandbox.org/permlink/wdY9WjsyEwYf6fwx)

```cpp
// This file is a "Hello, world!" in C++ language by Clang for wandbox.
#include <bits/stdc++.h>
#include <boost/rational.hpp>
#include <boost/format.hpp>
enum class Dim {
    mass,
    time,
    length,
    //...
};

bool operator==(Dim a, Dim b) {
    return static_cast<std::underlying_type_t<Dim>>(a)
        == static_cast<std::underlying_type_t<Dim>>(b);
}

std::ostream& operator<<(std::ostream& os, Dim b) {
    switch (b) {
        case Dim::time:
            return os << "time";
        case Dim::mass:
            return os << "mass";
        case Dim::length:
            return os << "length";
        default:
            return os;
    }
}

using rational = boost::rational<std::intmax_t>;

using U = std::pair<const Dim, std::pair<rational, rational>>;
using derived_unit = std::unordered_map<Dim, std::pair<rational, rational>>;

int main()
{
    auto reduce = [](Dim d,
                  std::pair<rational, rational> left,
                  std::pair<rational,rational> right){
        using std::min;
        return U{ d, {left.first + right.first,
                      min(left.second, right.second)}};
    };

    auto implies = [=](derived_unit left, derived_unit right){
        derived_unit result{};
        for (auto const& A : left) {
            [&]{
                for (auto const& B : right) {
                    if (A.first == B.first) {
                        result.emplace_hint(result.end(),
                                            reduce(A.first, 
                                                   A.second, 
                                                   B.second));
                        right.erase(B.first);
                        return;
                    }
                }
                result.emplace_hint(result.end(), A);
            }();   
        }
        for (auto const& e: right) result.insert(e);
        return result;
    };
    using std::pair;

    derived_unit left = {
        { Dim::length, { rational(2), rational(1) } },
        { Dim::time, { rational(-1), rational(1) } },
    };
    derived_unit right = {
        { Dim::mass, { rational(1), rational(1) } },
        { Dim::time, { rational(-1), rational(1) } },
    };
    
    auto res = implies(left, right);
    for (auto const& e: res) {
        std::cout
            << boost::format("(%1%, %2%)_%3% ")
                % e.second.first
                % e.second.second
                % e.first;
    }
}
```

**2nd step: Identifying the components required for type-level programming**

**Component list for type-level programming**

- **set of basic dimensions**

```cpp
enum class Dim {
    mass,
    time,
    length,
    //...
};
```

The type itself is already a set.

**=> define class and tag type member**

```cpp
class Length {
    using is_dimension = void;
};
```

---------------

- **`operator==` for basic dimensions**

```cpp
bool operator==(Dim a, Dim b) {
    return static_cast<std::underlying_type_t<Dim>>(a) == static_cast<std::underlying_type_t<Dim>>(b);
}
```

**=> a meta-function std::is_same**

---------------

- **type-level rational**

```cpp
using rational = boost::rational<std::intmax_t>;
```

**=> std::ratio**

---------------

- **A type that can be expressed in one dimension of derived units**

```cpp
using U = std::pair<const Dim, std::pair<rational, rational>>;
```

**=> define class units_t**


```cpp
template < class BaseDimension, // base dimension tag class
           class Exponent,      // std::ratio
           class Scale          // std::ratio
>
class units_t<BaseDimension, Exponent, Scale>
```

---------------

- **derived units representable type**

```cpp
using derived_unit = std::unordered_map<Dim, std::pair<rational, rational>>;
```

`unordered_map<Key, Value>` is a sequence of `std::pair<const Key, Value>`.
So we need a sequence of units_t.
We can use variadic templates.

**=> a class templates**

```cpp
template <class... UnitsT>
struct dimensional_t
{
};
```

---------------

- **helper function `reduce`**

```cpp
auto reduce = [](Dim d, std::pair<rational, rational> left, std::pair<rational,rational> right){
    using std::min;
    return U{ d, {left.first + right.first, min(left.second, right.second)} };
};
```

**=> meta-function**

```cpp
template <class D, class Exp1, class Exp2, class S1, class S2>
struct reduce<units_t<D, Exp1, S1>, units_t<D, Exp2, S2>> {
  using type = std::conditional_t<
      std::ratio_equal_v<std::ratio_add<Exp1, Exp2>, std::ratio<0>>,
      dimensionless<dimension_tag<D, ratio_max<Exp1, Exp2>>>,
      units_t<D, std::ratio_add<Exp1, Exp2>, ratio_min<S1, S2>>>;
};
```

---------------

- **main loop**

Put spirit into recursive class template instantiation.

```cpp
template <class...> struct type_list {};

template <class, class, class, class = void> struct quotient_;

template <class SP, class Head, class... Tail, class... Remainders>
struct quotient_<SP, type_list<Head, Tail...>,
                type_list<Remainders...>>
    : std::conditional_t<std::is_same_v<typename SP::dimension_type,
                                        typename Head::dimension_type>,
                         quotient_<SP, type_list<>,
                                  type_list<Remainders..., Tail...>,
                                  typename reduce<SP, Head>::type>,
                         quotient_<SP, type_list<Tail...>,
                                  type_list<Remainders..., Head>>> {};

template <class SP, class Inter, class... Tail, class... Remainders>
struct quotient_<SP, type_list<Tail...>, type_list<Remainders...>,
                Inter> {
  using result = type_list<Inter>;
  using remainder = type_list<Tail..., Remainders...>;
};

template <class SP, class... Remainders>
struct quotient_<SP, type_list<>, type_list<Remainders...>> {
  using result = type_list<SP>;
  using remainder = type_list<Remainders...>;
};

template <class, class, class> struct quotient_impl;

template <class Head, class... Tail, class... R, class... Results>
struct quotient_impl<type_list<Head, Tail...>, type_list<R...>, type_list<Results...>>
    : quotient_impl<type_list<Tail...>,
                    typename quotient_<Head, type_list<R...>,
                                       type_list<>>::remainder,
                    mitamagic::tlist_cat_t<
                        type_list<Results...>,
                        typename quotient_<Head, type_list<R...>,
                                           type_list<>>::result>> {};

template <class... R, class... Results>
struct quotient_impl<type_list<>, type_list<R...>, type_list<Results...>> {
  using result_type = dimensional_t<Results..., R...>;
};

// quotient facade
// Quotient = Dim -> Dim -> Dim
template <class, class> struct quotient;

template <class... LeftPhantomTypes,
          class... RightPhantomTypes>
struct quotient<dimensional_t<LeftPhantomTypes...>,
                dimensional_t<RightPhantomTypes...>> {
  using type = 
    mitamagic::tlist_remove_if_t<
      is_dimensionless_type,
      typename mitamagic::quotient_impl<
        mitamagic::type_list<LeftPhantomTypes...>,
        mitamagic::type_list<RightPhantomTypes...>,
        mitamagic::type_list<>
      >::result_type>;
};
```

---------------

Conclusion
------------

- It's a good idea to start by identifying what you need for type-level programming through runtime programming.
- By using phantom-type idiom, we can distinguish one type in various ways.
- C++ doesn't have a convenient language extension like Haskell, so we try hard at doing linear searches by relying on types.
- By using variadic templates, we can handle any dimension **as long as the template recursion allows**.