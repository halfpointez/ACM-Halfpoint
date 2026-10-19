#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<vector<i64>> Node;
vector<i64> beauty;
vector<i64> dp; 

void dfs(i64 u, i64 p) {
	i64 sum = 0;
	sum += beauty[u];
	for(auto v:Node[u]) {
		if(v == p) continue;
		dfs(v, u);
		if(dp[v] >= 0) sum += dp[v];		
	}

	dp[u] = sum;

}

void solve() {
	int n;
	cin >> n;
	Node.resize(n + 1);
	beauty.resize(n + 1);
	dp.resize(n + 1, 0);

	for(int i = 1; i <= n; i++) {
		cin >> beauty[i];
	}

	for(int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		Node[u].push_back(v);
		Node[v].push_back(u);
	}

	dfs(1, -1);
	i64 ans = dp[1];
	for(int i = 1; i <= n; i++) {
		ans = max(ans , dp[i]);
	}	
	cout << ans;

}

int main() {
	solve();
}