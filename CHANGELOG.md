## v0.0.1

勢いで作りすぎた、あとで書く。

## v0.1.0

- セルシウス温度サポート

ケルビンとセルシウス温度の変換が可能。
単位のシンボル付きのフォーマット形式出力にも対応している。

```cpp
#include <quantity.hpp>
#include <derived_units/dgree_celsius.hpp>

int main(){
    using namespace mitama;
    quantity<dgree_celsius_t, double> c1 = 10; // 10 [°C]

    // kelvin and dgree celsius are convertible to each other.
    quantity<kelvin_t, double> s = c1; // 283.15 [K]
    quantity<kelvin_t, double> c2 = s; // 10 [°C]
}
```

- 新機能:文脈依存単位変換

最終的な式の結果を与えることにより、式中の単位をいい感じに変換してくれる。

```cpp
#include <quantity.hpp>
#include <derived_units/dgree_celsius.hpp>
#include <expr.hpp>

int main(){
    using namespace Catch::literals;
    quantity<decltype(kelvin<>/second<>)>
        x = as_expr(1|kelvins) / (2|seconds) +
            as_expr(2|dgree_celsius) / (2|seconds);
    // x = 137.575 [K/s]

    quantity<decltype(kelvin<>/second<>)>
        y = (as_expr(11|kelvins) - as_expr(1|kelvins)) / (2|seconds) + 
            (as_expr(21|dgree_celsius) - as_expr(1|dgree_celsius)) / (2|seconds);
    // x = 15 [K/s]

}
```

## v0.2.0

作業予定

- 三角関数、逆三角関数
- サンプルコードとして、ハリーポッターの通貨を実装する
- 絶対零度以下の温度や、マイナスのカンデラなどをチェックできるように