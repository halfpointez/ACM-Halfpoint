#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 MOD = 1e9 + 7;
#define endl '\n'

void solve() {
	i64 n, k;
	cin >> n >> k;
	vector<i64> a(n);
	for(auto &i:a) cin >> i;
	vector<vector<i64>> dp(n + 1,vector<i64>(64, 0));
	
	dp[0][a[0]] = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= 63; j++) {
			dp[i][j] += dp[i - 1][j] % MOD;
			dp[i][j] %= MOD;
			dp[i][j & a[i]] += dp[i - 1][j] % MOD;
			dp[i][j & a[i]] %= MOD;
		}
		dp[i][a[i]] += 1;
		dp[i][a[i]] %= MOD;
	}

	i64 ans = 0;
	for(int i = 0; i <= 63; i++) {
		if(__builtin_popcount(i) == k) ans += dp[n - 1][i] % MOD;
	}
	cout << ans % MOD << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	i64 T;
	cin >> T;
	while (T--) {
		solve();
	}
	
}