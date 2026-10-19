# GCD 与扩展欧几里得

> 所属分类: 数论与数学 › 最大公约数_不定方程
> 复杂度: O(log n)

## 适用问题
- 求最大公约数 gcd / 最小公倍数 lcm
- 求解不定方程 ax + by = gcd(a, b) 的一组特解

## 6.3 GCD（最大公约数）
### 用法
求解两个整数的最大公约数，辗转相除递归即可。扩展欧几里得（exgcd）可求解不定方程 $ax + by = \gcd(a, b)$ 的一组特解。

### 完整模板
```cpp
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}
```
