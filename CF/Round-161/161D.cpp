#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<vector<i64>> Node;
vector<vector<i64>> dp;
i64 n, k;
i64 ans = 0;
void dfs(i64 u, i64 p) {
	dp[u][0] = 1;
	for(auto &v:Node[u]) {
		if (v == p) continue;

		dfs(v, u);

		for(int i = 0; i < k; i++) {
			ans += dp[u][i] * dp[v][k - i - 1];
		}

		for(int i = 1; i <= k; i++) {
			dp[u][i] += dp[v][i - 1];
		}

	}
	return;
}

void solve() {

	cin >> n >> k;
	Node.resize(n + 1);
	dp.resize(n + 1, vector<i64> (k + 1, 0));

	for(int i = 1; i < n; i++) {
		i64 u, v;
		cin >> u >> v;
		Node[u].push_back(v);
		Node[v].push_back(u);
	}

	dfs(1, -1);



	cout << ans << endl;
}

int main() {
	solve();
}