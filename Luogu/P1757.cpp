#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
#define endl '\n'

int main() {
	int m, n;
	cin >> m >> n;
	vector<i64> dp(m + 1);
	map<i64, vector<pair<i64, i64>>> mp; //a重量, b财富

	i64 z = 0;
	for(int i = 1; i <= n; i++) {
		i64 a, b, c;
		cin >> a >> b >> c;
		z = max(z, c);
		mp[c].push_back({a, b});
	}
	for(int i = 1; i <= z; i++) {
		for(int j = m; j >= 0; j--) {
			for(int k = 0; k < mp[i].size(); k++) {
				auto[w, v] = mp[i][k];
				if(j < w) continue;
				dp[j] = max(dp[j], dp[j - w] + v);
			}
		}
	}

	cout << dp[m];
}