#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int full = 1 << n;
	vector<string> sum_s;
	vector<string> a(n), b(n);
	vector<int> g(n), w(n);
	vector<vector<bool>> dp(full, vector<bool>(n, 0));

	for(int i = 0; i < n; i++) {
		dp[1 << i][i] = 1;
	}

	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		sum_s.push_back(a[i]);
		sum_s.push_back(b[i]);
	}

	sort(sum_s.begin(), sum_s.end());

	sum_s.erase(unique(sum_s.begin(), sum_s.end()), sum_s.end());
	

	for(int i = 0; i < n; i++) {
		g[i] = lower_bound(sum_s.begin(), sum_s.end(), a[i]) - sum_s.begin();
		w[i] = lower_bound(sum_s.begin(), sum_s.end(), b[i]) - sum_s.begin();
	}

	for(int mask = 0; mask < full; mask++) {
		for(int last = 0; last < n; last++) {
			if(!dp[mask][last]) continue;
			for(int i = 0; i < n; i++) {
				if(mask & (1 << i)) continue;
				if(g[last] == g[i] || w[last] == w[i]) {
					dp[mask | (1 << i)][i] = 1;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < full; i++) {
		for(int j = 0; j < n; j++) {
			if(dp[i][j]) ans = max(ans, __builtin_popcount(i));
		}
	}
	cout << n - ans << endl;

	
	
	
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}