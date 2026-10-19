# GCC内置函数

> 所属分类: 工具速查
> 用途: 比赛速查(不要求记忆, 用时查表)
> 备注: 2026-10-18 初稿, 待你核对

## 速查表

`__builtin_*` 是 GCC/Clang 的编译器内建函数, 不用 include 就能用; `__lg` 来自 libstdc++, 有 `<bits/stdc++.h>`(配合 `using namespace std;`)即可。**popcount/clz/ctz/parity/ffs 等返回 `int`; `__lg` 的返回类型随参数类型(int/long/long long)**。

| 函数 | 参数 | 返回 | 说明 |
|------|------|------|------|
| `__builtin_popcount(x)` | `unsigned int x` | `int` | x 的二进制中 1 的个数 |
| `__builtin_popcountl(x)` | `unsigned long x` | `int` | 同上, `unsigned long` 版 |
| `__builtin_popcountll(x)` | `unsigned long long x` | `int` | 同上, `unsigned long long` 版(64 位常用这个) |
| `__builtin_clz(x)` | `unsigned int x` | `int` | 高位起连续 0 的个数; **x = 0 时是 UB** |
| `__builtin_clzl(x)` / `__builtin_clzll(x)` | `unsigned long` / `unsigned long long` | `int` | 同上(64 位用 `clzll`) |
| `__builtin_ctz(x)` | `unsigned int x` | `int` | 低位起连续 0 的个数(即最低位 1 的下标, 0-based); **x = 0 时是 UB** |
| `__builtin_ctzl(x)` / `__builtin_ctzll(x)` | `unsigned long` / `unsigned long long` | `int` | 同上(64 位用 `ctzll`) |
| `__builtin_parity(x)` | `unsigned int x` | `int` | x 中 1 的个数奇偶: 奇数 → 1, 偶数 → 0 |
| `__builtin_parityl(x)` / `__builtin_parityll(x)` | `unsigned long` / `unsigned long long` | `int` | 同上(64 位用 `parityll`) |
| `__builtin_ffs(x)` | `int x` | `int` | 最低位 1 的位置, **1-based**; x = 0 → 返回 0 |
| `__builtin_ffsl(x)` / `__builtin_ffsll(x)` | `long` / `long long` | `int` | 同上(64 位用 `ffsll`) |
| `__lg(x)` | 正整数(int / long long / unsigned 均可) | 同参数类型 | `⌊log2 x⌋` = 最高位 1 的下标; x = 0 时是 UB; libstdc++ 内部函数(非标准) |

## 常用组合

```cpp
int pc  = __builtin_popcountll(x);   // x 中 1 的个数
int hi  = 63 - __builtin_clzll(x);   // x > 0: 最高位 1 的下标 = ⌊log2 x⌋
int lo  = __builtin_ctzll(x);        // x > 0: 最低位 1 的下标(0-based)
int f   = __builtin_ffsll(x);        // x ≠ 0: 最低位 1 的下标 + 1(1-based)
int odd = __builtin_parityll(x);     // x 中 1 的个数为奇数 → 1
int l2  = __lg(x);                   // 同 hi, 写法更短
```

求最高位下标的两种写法: 32 位数 `31 - __builtin_clz(x)`, 64 位数 `63 - __builtin_clzll(x)`。

## 坑

- **64 位必须用 `ll` 后缀**: `__builtin_popcount(1LL << 40)` 会先把参数截断成 `unsigned int`(高 32 位丢掉), 结果是 0, 编译器只给个 `-Woverflow` 警告; 应写 `__builtin_popcountll(1LL << 40)`。同理 64 位用 `clzll` / `ctzll` / `ffsll` / `parityll`。
- **Windows(MinGW) 下 `long` 是 32 位**(`__builtin_popcountl(~0UL)` 得 32), Linux 评测机下 `long` 是 64 位; 所以 64 位的数一律用 `ll` 版最保险。
- **`clz` / `ctz` / `__lg` 在 0 上不可用**: 参数为 0 时行为未定义, 用前先判 `x != 0`(负数对这几个函数也无意义)。
- **返回类型是 `int`(不是 `long long`)**: 结果不超过 64, 本身不会溢出; 但和别的大数相乘时注意先转, 如 `1LL * __builtin_popcountll(x) * y`。
- **`ffs` 与 `ctz` 的下标基准不同**: `ffs` 是 1-based(最低位为 1), `ctz` 是 0-based(最低位为 0), 混用时差 1。
- **C++20 起有标准版可平替**: `std::popcount` / `std::countl_zero` / `std::countr_zero` / `std::bit_width` / `std::has_single_bit`(都在 `<bit>` 头); 注意它们要求 C++20 且参数必须是**无符号**类型(传 `int` 编译不过)。本板子按 C++17, 统一用 `__builtin_*`。
