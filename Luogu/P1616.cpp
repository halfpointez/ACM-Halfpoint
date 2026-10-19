#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
#define endl '\n'
signed main() {
	int t, m;
	cin >> t >> m;
	vector<int> a(m + 1, 0), b(m + 1, 0);
	vector<int> dp(t + 1, 0);
	for(int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i];
	}
	for(int i = 1; i <= m; i++) {
		for(int j = a[i]; j <= t; j++) {
			dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
		}
	}

	cout << dp[t];


}