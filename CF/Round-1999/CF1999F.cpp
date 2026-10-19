#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 MOD = 1e9 + 7;
const int MAXN = 1000000 + 5; // 根据题目 n 的最大值调整

vector<i64> fact(MAXN), invfact(MAXN);

// 快速幂
i64 modpow(i64 a, i64 e) {
    i64 res = 1;
    while (e) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

// 预处理阶乘和阶乘逆元
void init() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
}

// 组合数 C(n, r)
i64 C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt1 += x;
    }

    int cnt0 = n - cnt1;
    int need = (k + 1) / 2; // 中位数为 1 至少需要多少个 1

    i64 ans = 0;

    for (int ones = need; ones <= k && ones <= cnt1; ones++) {
        int zeros = k - ones;
        if (zeros < 0 || zeros > cnt0) continue;

        ans = (ans + C(cnt1, ones) * C(cnt0, zeros)) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}