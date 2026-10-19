#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
#define endl '\n'
vector<vector<i64>> Node;
vector<vector<i64>> dp; // 0为联通块是s的代价 1为连通块是p的代价
const i64 INF = 1e9;

void dfs(i64 u, i64 p) {
	for(auto &v:Node[u]) {
		if(v == p) continue;
		dfs(v, u);
		dp[u][0] += min(dp[v][0], dp[v][1] + 1);
		dp[u][1] += min(dp[v][0] + 1, dp[v][1]);
	}
}

void solve() {
	i64 n;
	cin >> n;
	Node.assign(n + 1, {});
	dp.assign(n + 1, vector<i64>(2));
	for(int i = 2; i <= n; i++) {
		i64 u;
		cin >> u;
		Node[i].push_back(u);
		Node[u].push_back(i);
	}
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++) {
		if(s[i - 1] == 'C') {
			dp[i][0] = 0;
			dp[i][1] = 0;
		} else if(s[i - 1] == 'S') {
			dp[i][0] = 0;
			dp[i][1] = INF;
		} else {
			dp[i][0] = INF;
			dp[i][1] = 0;
		}
	}

	dfs(1, -1);
	cout << min(dp[1][0], dp[1][1]) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}