#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	i64 n, m;
	cin >> n >> m; //n钱 m个
	vector<pair<i64, i64>> wupin(m + 1);
	map<i64, vector<pair<i64, i64>>> group; //重 价值
	map<i64, vector<pair<i64, i64>>> div_bag;
	for(int i = 1; i <= m; i++) {
		i64 v, w, q;
		cin >> v >> w >> q;
		if(q == 0) {
			wupin[i] = {v, v * w};
		} else group[q].push_back({v, v * w});
		
		
	}

	for(int i = 1; i <= m; i++) {

		if(group[i].empty()) {
			div_bag[i].push_back(wupin[i]);
			continue;
		}
		div_bag[i].push_back({wupin[i].first, wupin[i].second});
		for(auto [weight, value]:group[i]) {
			i64 sz = div_bag[i].size();
			for(int j = 0; j < sz; j++) {
				auto[w, v] = div_bag[i][j];
				div_bag[i].push_back({w + weight, v + value});
			}
		}
		div_bag[i].push_back({0, 0});
	}

	vector<i64> dp(n + 1, 0);
	for(int i = 1; i <= m; i++) {
		for(int j = n; j >= 0; j--) {
			for(int k = 0; k < div_bag[i].size(); k++) {
				auto[w, v] = div_bag[i][k];
				if(j < w) continue;
				dp[j] = max(dp[j], dp[j - w] + v);
			}
		}
	}

	cout << dp[n];
}