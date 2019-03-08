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

- dimensionalディレクトリ下にファイルを移動

- バグ修正に伴って`<dimensional/comparison.hpp>`が削除、`quantity_t`のメンバ関数になった
### **新機能**

- `quantity<radian_t, T>`を引数に取る三角関数、`quantity<radian_t, T>`を返す逆三角関数の追加

```cpp
#include <diemnsional/quantity.hpp>
#include <dimensional/math/trigonometric.hpp>

int main() {
    using mitama::quantity;

    quantity<mitama::radian_t> rad = 3;
    // 戻り値は単位なし
    double res1 = sin(rad); // ADL
    double res2 = cos(rad); // ADL
    double res3 = tan(rad); // ADL

    // 戻り値は単位付き
    quantity<mitama::radian_t> rad1 = mitama::asin(rad); // ADL不可能
    quantity<mitama::radian_t> rad2 = mitama::acos(rad); // ADL不可能
    quantity<mitama::radian_t> rad3 = mitama::atan(rad); // ADL不可能

}
```

- `quantity_t`に`validate()`メンバ関数を実装

```cpp
#include <diemnsional/quantity.hpp>
#include <dimensional/si/all.hpp>

int main(){
    using mitama::quantity;

    auto validator = [](auto v) -> std::optional<decltype(v)> {
        if (v.get() < 0)
            return std::nullopt;
        else
            return std::optional(v);
    };

    quantity<mitama::meter_t> length = -1; // おっと、負の長さ！

    if (auto opt = length.validate(validator); opt)
    { // OK
        opt.value(); // 値を使う
    }
    else
    { // NG
        throw std::runtime_error("error: negative length");
    }
}
```

### **ドキュメント・サンプルコード**

- サンプルコードとして、ハリーポッターの通貨を実装

基本次元クラスを独自に定義する方法がわかるサンプルを作りました。

[`src/wizarding-currency/wizarding_currency.hpp`](src/wizarding-currency/wizarding_currency.hpp)

### **バグ修正**

- 絶対温度とセルシウス温度の比較に対応するように比較演算子を修正（quantityのメンバ関数になったため、`<dimensional/comparison.hpp>`は削除）

- 単位のフォーマット形式を`value [ units ]`から`value [units]`に修正（`[]`の中のスペースを消した）

- `make_unit_t`のスケールの処理が掛け算されていなかったのを修正

- 式木とquantityの四則演算のオーバーロードの曖昧性を修正


## v0.3.0

リリース予定

- 温度差などを型上で表せるdelta型
- SI単位系のよく使う単位の整備
- 度数法のサポート
