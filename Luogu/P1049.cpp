#include <bits/stdc++.h>
using namespace std;
int main() {
	int V, n;
	cin >> V >> n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	vector<vector<bool>> dp(n + 1, vector<bool>(V + 1, 0)); //考虑前i个物品 体积j能否被刚好装满 能则bool = 1
	for(int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= V; j++) {
			bool k = 0;
			if(j - v[i] >= 0) k |= dp[i - 1][j - v[i]];
			k |= dp[i - 1][j];
			dp[i][j] = k;
			if(k) ans = max(ans, j);
		}
	}

	cout << V - ans;
}