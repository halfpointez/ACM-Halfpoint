#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

const i64 MAXN = 2e5 + 5;

vector<i64> primes;
vector<bool> is_not_prime;
vector<i64> sp;
vector<vector<i64>> fac;
vector<i64> dp;
vector<i64> vis;

void euler_sieve(i64 n) {
    is_not_prime.assign(n + 1, 0);
    sp.assign(n + 1, 0);
    is_not_prime[0] = is_not_prime[1] = 1;
    for (i64 i = 2; i <= n; i++) {
        if (!is_not_prime[i]) {
            primes.push_back(i);
            sp[i] = i;
        }
        for (i64 p : primes) {
            if (i * p > n) break;
            is_not_prime[i * p] = 1;
            sp[i * p] = p;
            if (i % p == 0) break;
        }
    }
}

void pre() {
    fac.resize(MAXN);
    for (i64 i = 2; i < MAXN; i++) {
        i64 x = i;
        while (x > 1) {
            i64 p = sp[x];
            fac[i].push_back(p);
            while (x % p == 0) x /= p;
        }
    }
}

i64 dfs(i64 x, i64 k) {
    if (x <= k) return 0;
    if (dp[x] != -1) return dp[x];
    i64 ans = LLONG_MAX;
    for (i64 p : fac[x]) {
        i64 sub = dfs(x / p, k);
        ans = min(ans, 1 + p * sub);
    }
    dp[x] = ans;
    vis.push_back(x);
    return ans;
}

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    vis.clear();
    i64 total = 0;
    for (i64 x : a) {
        total += dfs(x, k);
    }
    cout << total << endl;
    for (i64 x : vis) {
        dp[x] = -1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    euler_sieve(MAXN);
    pre();
    dp.assign(MAXN, -1);

    i64 t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}