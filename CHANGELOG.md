## v0.0.1

勢いで作りすぎた、あとで書く。

## v0.1.0

- セルシウス温度サポート

ケルビンとセルシウス温度の変換が可能。
単位のシンボル付きのフォーマット形式出力にも対応している。

```cpp
#include <quantity.hpp>
#include <nonsi_units/degree_celsius.hpp>

int main(){
    using namespace mitama;
    quantity<degree_celsius_t, double> c1 = 10; // 10 [°C]

    // kelvin and degree celsius are convertible to each other.
    quantity<kelvin_t, double> s = c1; // 283.15 [K]
    quantity<kelvin_t, double> c2 = s; // 10 [°C]
}
```

- 新機能:文脈依存単位変換

最終的な式の結果を与えることにより、式中の単位をいい感じに変換してくれる。

```cpp
#include <quantity.hpp>
#include <nonsi_units/degree_celsius.hpp>
#include <expr.hpp>

int main(){
    using namespace Catch::literals;
    quantity<decltype(kelvin<>/second<>)>
        x = as_expr(1|kelvins) / (2|seconds) +
            as_expr(2|degree_celsius) / (2|seconds);
    // x = 137.575 [K/s]

    quantity<decltype(kelvin<>/second<>)>
        y = (as_expr(11|kelvins) - as_expr(1|kelvins)) / (2|seconds) + 
            (as_expr(21|degree_celsius) - as_expr(1|degree_celsius)) / (2|seconds);
    // x = 15 [K/s]

}
```

## v0.2.0

### **破壊的変更**

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


## v3.0.0
### **新機能**

- metre(meter), litre(liter)などイギリス（フランス？）綴りの追加

- 定義済みSI誘導単位の追加（120個ほど）

`<dimensional/derived_units/named_units.hpp>`を参照してくれ。

- `refinement` 型

`quantity`型の単位を推論しつつ、目的にそった次元を持つことをコンパイル時に保証させることができる機能。

次は`(2|meters) * (7|meters)`という量が面積（L^2）の次元を**完全に**持っていなければコンパイルエラーになる。
`m^2`は`L^2`の次元であるので、このコードはrefinement（篩）を通過しコンパイルできる。

```cpp
quantity_t a1 = refined<area_r> |= (2|meters) * (7|meters);
```

単位まで指定する場合はつぎのように書くべきである。
単位が違った場合には自動的な単位変換が行われる点で異なる。

```cpp
quantity<meter_t, int> a1 = (2|meters) * (7|meters);
```

`refined`は次元のみを検査し、単位までは検査しない。



つぎの例は、コンパイルが通らない。
`m`は`L`の次元であり、`L^2`ではないからである。

```cpp
quantity_t a3 = refined<area_r> |= (2|millimeters); // error!
```

次は`(2|meters) * (2|meters) * (2|kilograms) / (2|second<2>)`という量が質量（M）の次元を**部分的に**持っていなければコンパイルエラーになる。

```cpp
quantity_t a3 = partial_refined<sym::M<>> |= (2|meters) * (2|meters) * (2|kilograms) / (2|second<2>);
```

- `delta<T>` 型（partial suport）

温度の足し算には変換が必要である。
しかし、絶対温度にセルシウス温度の温度差を足す場合には変換は必要がない。
型上で**差**を表す必要があるような雰囲気である。

入れ物だけ用意した、細かい実装は次のリリースで。

```cpp
// 温度差を表す
delta d = (22|kelvins) * (2|kelvins);
```

- 度数法のサポート

`<dimensional/derived_units/nonsi_units/nonsi_degree_angle.hpp>`

```cpp
#include <dimensional/quantity.hpp>
#include <dimensional/nonsi_units/nonsi_degree_angle.hpp>
#include <dimensional/derived_units/named_units.hpp>

int main() {
    // 相互変換可能
    mitama::quantity<degree_angle_t> c = 180;
    mitama::quantity<radian_t> r = c; // pi [rad]
}
```

### バグ修正

- critical: 次元演算のコア部分のメタプログラミングのバグを修正

### コントリビューター

- [yo-kanyukari](https://github.com/yo-kanyukari): 度数法のサポート

## v0.4.0

### **新機能**

- `delta<T>` (full support)

差であることを型で明示的に表すことができる。
これにより、温度差をうまく扱えるようになった。

delta型はquantity_t型との四則演算が行える。

```cpp
#include <dimensional/quantity.hpp>
#include <dimensional/si/kelvin.hpp>
#include <dimensional/nonsi_units/degree_delsius.hpp>
#include <dimensional/delta.hpp>

int main() {
    using namespace mitama;
    quantity<si::degree_delsius> c = 100;
    // 温度差なので単位変換なしで計算される
    quantity<si::degree_delsius> res = c + delta( (20|si::kelvins) -  (10|si::kelvins) ); // 100 + 10 = 110
}
```


### バグ修正

- `value / quantity_t`と`quantity_t / value`が両方許可されていたが、前者を許可しない実装になった。
- 無次元量のフォーマットがバグっていてコンパイルエラーになる問題を修正


### ドキュメント

- [environment](https://loligothick.github.io/mitama-dimensional/)として公開（執筆途中）


## v0.5.0

### **新機能**

- new math functions
  - fmod
  - remainder
  - dim

### バグ修正

- 以下の数学関数の結果の型がおかしくなるバグを修正
  - abs
  - nearest integer系すべて
  - pow系すべて
  - root系すべて


### ドキュメント

- [environment](https://loligothick.github.io/mitama-dimensional/)として公開中（2/3ほど書き終わった）

## v0.6.0

### **新機能**

なし

### バグ修正

- SI derived unitsのファイルを細分化


### Testing


- フォーマット系テストのカバレッジをほぼ100%に
- テストも細分化


### ドキュメント

- [environment](https://loligothick.github.io/mitama-dimensional/)として公開中（Basic Conceptsを書き足した）

## v0.9.0

### **新機能**

- 単項 +/- 演算子サポート
- 無次元の次元量のみ特別に暗黙のUnderlying Typeへの変換を許可
- `get()` と同じ用途の関数 `value()` を追加
- Into Traitと`qantity_t::into()`メソッドを追加

