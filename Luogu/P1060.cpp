#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	i64 n, m;
	cin >> n >> m;
	vector<i64> dp(n + 1, 0);
	vector<i64> value(m + 1);
	vector<i64> val(m + 1);
	for(int i = 1; i <= m; i++) {
		i64 u, v;
		cin >> u >> v;
		value[i] = u * v;
		val[i] = u;
	}
	for(int i = 1; i <= m; i++) {
		for(int j = n; j >= val[i]; j--) {
			dp[j] = max(dp[j], dp[j - val[i]] + value[i]);
		}
	}

	cout << dp[n] << endl;
}