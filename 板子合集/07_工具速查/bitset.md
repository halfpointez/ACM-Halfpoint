# bitset

> 所属分类: 工具速查
> 用途: 比赛速查(不要求记忆, 用时查表)
> 备注: 2026-10-18 初稿, 待你核对

## 声明

```cpp
bitset<100005> b;              // N 必须是编译期常量(模板参数); 内存约 N/8 字节
const int N = 100003;
bitset<N> f;                   // 可以: const int 由常量表达式初始化
// int n; cin >> n;  bitset<n> g;   // 不行: n 不是编译期常量
bitset<8> h(string("1010"));   // 从字符串构造: 右端是低位(与 to_string 方向一致), 字符串短了高位补 0
```

≤ 64 位的需求直接 `unsigned long long` 当位掩码就行(还能配 `__builtin_popcountll`), bitset 用在 N 更大或需要大量整段位运算的场合。

## 位运算

```cpp
bitset<8> a(5);              // 00000101
bitset<8> b(string("1010")); // 00001010
a |= b;                      // 00001111
cout << (a << 1) << '\n';    // 00011110(移出界的位直接丢)
cout << ~a << '\n';          // 11110000(对全部 N 位取反)
a[0] = 1;                    // 第 0 位(最低位)可读可写
```

- 支持 `& | ^ ~ << >>` 与 `==` / `!=`; 其中 `& | ^` 两边必须同类型 / 同 N, `<<` / `>>` 的右操作数是整型移位数(如 `a << 1`), 不是 bitset。
- 输出方向: `cout << b` 与 `b.to_string()` 一致, **最左是最高位**(下标 N-1); 从字符串构造也是同一方向, 方向不用特别记。

## 成员函数速查表

| 成员 | 例子 | 返回 / 说明 |
|------|------|-------------|
| `test(i)` | `b.test(3)` | 第 i 位是否为 1; **i ≥ N 抛 `out_of_range`** |
| `operator[]` | `b[i] = 1` | 访问第 i 位(可读可写); **不做越界检查**(越界是 UB) |
| `set(i)` / `set()` | `b.set(2)` / `b.set()` | 第 i 位置 1 / 全 1; 越界抛 `out_of_range` |
| `set(i, v)` | `b.set(2, false)` | 第 i 位设为 v |
| `reset(i)` / `reset()` | `b.reset(2)` / `b.reset()` | 第 i 位置 0 / 全 0 |
| `flip(i)` / `flip()` | `b.flip(2)` / `b.flip()` | 第 i 位取反 / 全取反 |
| `count()` | `b.count()` | 1 的个数(约 O(N/64)) |
| `size()` | `b.size()` | N(编译期常量) |
| `any()` / `none()` | `b.any()` / `b.none()` | 是否存在 1 / 是否全 0 |
| `all()` | `b.all()` | 是否全 1(C++11 起) |
| `to_string()` | `b.to_string()` | 转 `string`: N 个 '0'/'1', 最左是最高位 |
| `to_ulong()` / `to_ullong()` | `b.to_ullong()` | 转 `unsigned long` / `unsigned long long`(C++11); **值超范围抛 `overflow_error`** |

## 坑

- **N 必须是编译期常量**: `int n; cin >> n; bitset<n> b;` 编译不过; 规模不定时用 `vector<bool>` 或按题目上界开固定 N。
- **`to_ullong()` 溢出会抛异常**: `bitset<64>` 全 1 没问题(= 2^64-1), 但 N > 64 时只要有下标 ≥ 64 的位是 1(值 ≥ 2^64)就抛 `std::overflow_error`; 不要拿它直接转大 bitset。
- **`operator[]` 不查越界**; `test(i)` / `set(i)` / `reset(i)` / `flip(i)` 越界会抛 `out_of_range`。
- **`to_string()` 是 O(N)**(大 bitset 别在循环里反复调用)。
- 字符串构造时含非 '0'/'1' 字符会抛 `std::invalid_argument`。

## 典型用途

### 可达性 / 传递闭包

用 `bitset<N>` 数组当邻接矩阵, 一次 `|=` 处理一整行, 传递闭包 O(n³/64):

```cpp
const int N = 2005;
bitset<N> g[N];              // g[i] 的第 j 位 = i 能一步到 j
// 加边: g[u].set(v);
for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
        if (g[i].test(k)) g[i] |= g[k];
// 之后 g[i].test(j) 即 i 能否到达 j
```

### 集合表示 / 状态压缩

一个 bitset 就是一个集合: `|=` 并, `&` 交, `& ~` 差, `count()` 大小, 判包含 `(A & B) == B`; 26 个字母之类的"出现过哪些"用它很顺手:

```cpp
bitset<26> has;
for (char c : s) has.set(c - 'a');
int kinds = has.count();     // 出现了多少种字母
```

### 背包可行性 / 子集和(0/1)

`f` 的第 s 位表示"和为 s 可达", 每个数用一次:

```cpp
bitset<MAXS> f;
f[0] = 1;
for (int i = 1; i <= n; i++) f |= f << a[i];
// 询问: f.test(s)
```

单次转移 O(MAXS/64), 比朴素 DP 快约 64 倍; MAXS 按总和上界开。
