# Dimensional refinement

>"I mean, it's sort of exciting, isn't it, breaking the rules?" — Hermione Granger, Harry Potter and the Order of the Phoenix

----------------------


defined in header [`<dimensional/refinement.hpp>`]().

## Refinement type

A function that can be guaranteed at compile time to have dimensions in accordance with the purpose while inferring units of quantity type.

The following is a compilation error if the quantity `(2 | meters) * (7 | meters)` does not have the dimension of area $ L^2$  completely.
This code can be compiled through refinement, since $m^2$  is of dimension $ L^2$ .

```cpp
quantity_t a1 = refined<area_r> |= (2|meters) * (7|meters);
```


If you want to specify the unit should be written as follows. The difference is that automatic unit conversion is performed when units are different.
`refined` examines only the dimensions, not the units.


```cpp
quantity<meter_t, int> a1 = (2|meters) * (7|meters);
```



The following example does not pass compilation. This is because m is the dimension of $ L$  and not $ L^2$ .

```cpp
quantity_t a3 = refined<area_r> |= (2|millimeters); // error!
```

## Partial refinement type

The following is a compilation error if the quantity `(2 | meters) * (2 | meters) * (2 | kilograms) / (2 | second <2>)` does not partially have the dimension of mass $M$ .
The compilation passes because it actually has.

```cpp
quantity_t a3
    = partial_refined<sym::M<>>
    |= (2|meters) * (2|meters) * (2|kilograms) / (2|second<2>);
```