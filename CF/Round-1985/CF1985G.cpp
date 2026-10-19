#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 MOD = 1e9 + 7;

i64 qpow(i64 a, i64 b) {
	i64 res = 1;
	while (b) {
		if(b & 1) res *= a;
		a *= a;
		a %= MOD;
		b >>= 1;
		res %= MOD;
	}
	return res % MOD;
}

void solve() {
    i64 l, r, k;
    cin >> l >> r >> k;
    i64 cnt = 0;
    for (int i = 0; i < 10; i++) {
        if (k * i >= 10) break;
        cnt++;
    }
    i64 ans = (qpow(cnt, r) - qpow(cnt, l) + MOD) % MOD;
    cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();	
	}
	
} 